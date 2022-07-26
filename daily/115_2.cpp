#include<bits/stdc++.h>
using namespace std;

/*
    拓扑排序,每次选择一个入度为0的节点，删除他的所有边，直到图中不存在入度为0的点为止
    一般用来排序一些具有依赖关系的任务

    使用拓扑排序解该题，只需要保证每次入度为0的节点都只有一个，即可确定各数字之间的偏序关系
*/
struct Listnode{
    int val;
    Listnode* next;
    Listnode():val(0),next(nullptr){}
    Listnode(int v):val(v),next(nullptr){}
    Listnode(int v, Listnode* p):val(v),next(p){}
};


class Solution {
private:
    //邻接表数据结构
    class Graph{
    public:
        vector<Listnode*> head;
        //节点数
        Graph(int n){
            head = vector<Listnode*>(n, nullptr);
            for(int i=0;i < n;i++)
                head[i] = new Listnode(i);
        }
        //添加边[i,j]
        void add(int i, int j){
            //头插法
            Listnode* p = new Listnode(j);
            p->next = head[i]->next;
            head[i]->next = p;
        }

        //删除边[i,j]
        bool erase(int i, int j){
            Listnode* p = head[i];
            while(p->next != nullptr){
                if(p->next->val == j){
                    Listnode* q = p->next;
                    p->next = q->next;
                    delete q;
                    return true;
                }
                p = p->next;
            }
            return false;
        }
    };

public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size()+1;
        Graph graph(n);
        vector<int> cnt(n);
        unordered_set<int> v0;   //存放入度为0的点
        int c = 0;
        for(auto sequence:sequences){
            for(int i=1;i < sequence.size();i++){
                graph.add(sequence[i-1], sequence[i]);
                ++cnt[sequence[i]];
                ++c;
            }
        }
        for(int i=1;i < n;i++){
            if(cnt[i] == 0)
                v0.insert(i);
        }
        while(!v0.empty()){
            if(v0.size() != 1)
                return false;
            int i = *v0.begin();
            //删除i节点的所有边
            Listnode* p = graph.head[i];
            while(p->next != nullptr){
                Listnode* q = p->next;
                p->next = q->next;
                --cnt[q->val];
                --c;
                if(!cnt[q->val])
                    v0.insert(q->val);
                delete q;
            }
            v0.erase(i);
        }
        if(c)
            return false;
        return true;
    }
};


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> sequences = {{1,2},{1,3},{2,3}};
    bool res = Solution().sequenceReconstruction(nums, sequences);
    return 0;
}