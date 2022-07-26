#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int v):val(v),next(nullptr){}
    ListNode(int v, ListNode* p):val(v),next(p){}
};

//邻接表数据结构
class Graph{
private:
    vector<ListNode*> head;
public:
    //节点数
    Graph(int n){
        head = vector<ListNode*>(n, nullptr);
        for(int i=0;i < n;i++)
            head[i] = new ListNode(i);
    }
    //添加边[i,j]
    void add(int i, int j){
        //头插法
        ListNode* p = new ListNode(j);
        p->next = head[i]->next;
        head[i]->next = p;
    }

    //删除边[i,j]
    bool erase(int i, int j){
        ListNode* p = head[i];
        while(p->next != nullptr){
            if(p->next->val == j){
                ListNode* q = p->next;
                p->next = q->next;
                delete q;
                return true;
            }
            p = p->next;
        }
        return false;
    }
};

int main(void){
    vector<pair<int,int>> egdes = {{1,2}, {1,3}, {2,4}, {4,1}};
    Graph graph(5);
    for(auto [i,j]:egdes){
        graph.add(i, j);
    }
    bool res = graph.erase(1,3);
    res = graph.erase(1,3);
    return 0;
}