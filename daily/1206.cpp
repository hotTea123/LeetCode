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
        level = 1;
        SkiplistNode* head = new SkiplistNode(-1, 1);
    }
    
    bool search(int target) {
        SkiplistNode* p = head;
        for(int i=level-1;i >=0;i--){
            while(p->next[i] != nullptr && p->next[i]->val <= target)
            if(p->next[i]->val == target)
                return true;
                p = p->next[i];
        }
        return false;
    }

    void add(int num) {
        int l = randomLevel();
        SkiplistNode *node = new SkiplistNode(num, l);
        vector<SkiplistNode*> update(l);
        if(l > level){
            head->next.emplace_back(nullptr);
            update[l-1] = head;
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
    return 0;
}