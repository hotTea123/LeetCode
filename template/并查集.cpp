#include<bits/stdc++.h>
using namespace std;

class UnionFindSet{
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    UnionFindSet(int n){
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i=0;i < n;i++)
            parent[i] = i;
        count = 1;
    }

    //返回当前节点的根节点
    int Find(int x){
        if(parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    //连接x，y
    void Union(int x, int y){
        int xParent = Find(x), yParent = Find(y);
        if(xParent == yParent)
            return;
        if(rank[xParent] > rank[yParent]){
            parent[yParent] = xParent;
            rank[xParent] += rank[yParent];
        }else{
            parent[xParent] = yParent;
            rank[yParent] += rank[xParent];
        }
        int a = max(rank[xParent], rank[yParent]);
        count = max(count, a);
    }

    int getRank(int x){
        return rank[x];
    }

    int getCount(){
        return count;
    }
};