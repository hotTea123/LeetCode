#include<bits/stdc++.h>
using namespace std;

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