#include<bits/stdc++.h>
using namespace std;

class UnionFindSet{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFindSet(int n){
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i=0;i < n;i++)
            parent[i] = i;
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
    }

    int getRank(int x){
        return rank[Find(x)];
    }
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> restrictedNode;
        for(int i:restricted)
            restrictedNode.insert(i);
        UnionFindSet ufs(n);
        for(auto edge:edges){
            if(restrictedNode.find(edge[0]) != restrictedNode.end() || restrictedNode.find(edge[1]) != restrictedNode.end())
                continue;
            ufs.Union(edge[0], edge[1]);
        }
        return ufs.getRank(0);
    }
};
