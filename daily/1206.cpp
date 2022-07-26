#include<bits/stdc++.h>
using namespace std;

/*
    实现中的注意事项：
    1.添加和删除的时候，使用一个vector存要添加和删除的前一个位置
    2.添加时，待添加节点的层数每次往上加一层的概率是50%
    3.添加时，对于多个值相同的节点需要进行妥善的处理，我在每一层都找到与待添加nums值相同的最后一个节点，
    并把他放到更新数组里面，这样就可以保证最终待添加节点也会在与其值相同的所有节点的后面
    4.删除时，对于多个值相同的节点的处理有些棘手，如果只是在每层单纯的比较值，不管你是删除所有值相同的
    第一个节点还是最后一个节点，都可能导致你最后每层要删除的不是同一个节点，而是一些值相同的不同节点，
    因此需进行地址的比较以确保每层删除同一节点，具体做法是：设置一个bool变量标志是否是第一次找到元素num，
    因为是从上层往下层遍历，因此找到的那个num是level最多且那层level上的第一个与num相等的元素，之后在
    后面每一层查找的时候都需要判断找到的节点地址与第一次找到的那个是否一致。
*/

struct SkiplistNode{
    int val;
    vector<SkiplistNode*> next;
    SkiplistNode(int v, int n):val(v), next(vector<SkiplistNode*>(n, nullptr)){};
};

class Skiplist {
private:
    int level;
    SkiplistNode* head;

    unsigned seed;
    int randomLevel(){
        int l = 1;
        while(rand()%2 && l <= level)
            ++l;
        return l;
    }

public:
    Skiplist() {
        level = 0;
        head = new SkiplistNode(-1, 0);
    }
    
    bool search(int target) {
        SkiplistNode* p = head;
        for(int i=level-1;i >=0;i--){
            while(p->next[i] != nullptr && p->next[i]->val <= target){
                p = p->next[i];
                if(p->val == target)
                    return true;
            }
        }
        return false;
    }

    void add(int num) {
        int l = randomLevel();
        SkiplistNode *node = new SkiplistNode(num, l);
        vector<SkiplistNode*> update(l);
        if(l > level){
            head->next.emplace_back(nullptr);
            ++level;
        }
        SkiplistNode* p = head;
        for(int i=level-1;i >=0;i--){
            while(p->next[i] != nullptr && p->next[i]->val <= num)
                p = p->next[i];
                
            if(i < l)
                update[i] = p;
        }
        for(int i=0;i < l;i++){
            node->next[i] = update[i]->next[i];
            update[i]->next[i] = node;
        }
    }

    bool erase(int num) {
        vector<SkiplistNode*> deleteNode(level, nullptr);
        SkiplistNode* p = head;
        int flag = true;  //标志是否是第一次找到元素num
        for(int i=level-1;i >=0;i--){
            while(p->next[i] != nullptr && p->next[i]->val < num){
                //删除第一个出现的num
                p = p->next[i];
            }
            while(p->next[i] != nullptr && p->next[i]->val == num){
                //判断相等的数是否跟第一次取的那个数地址一样
                //开始写的&p->next[i] == &deleteNode[i+1]->next[i+1]，然后错了
                if(flag || p->next[i] == deleteNode[i+1]->next[i+1]){
                    deleteNode[i] = p;
                    flag = false;
                    break;
                }
                p = p->next[i];
            }
        }
        
        if(deleteNode[0] == nullptr)
            return false;
        p = deleteNode[0]->next[0];   //待删除节点
        for(int i=0;i < level;i++){
            if(deleteNode[i] == nullptr)
                break;
            deleteNode[i]->next[i] = p->next[i];
        }
        delete p;
        return true;
    }
};

int main(){
    Skiplist skiplist;
    skiplist.add(5);
    bool res = skiplist.search(5);
    for(int i=0;i < 10;i++){
        skiplist.add(i);
    }
    res = skiplist.search(7);
    res = skiplist.erase(5);
    res = skiplist.search(5);
    return 0;
}