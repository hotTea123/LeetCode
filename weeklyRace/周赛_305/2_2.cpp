#include<bits/stdc++.h>
using namespace std;

//dfs
class Solution {
private:
    int DFS(int n, vector<vector<int>>& node, vector<bool>& visit){
        int ret = 1;
        visit[n] = true;
        for(auto i:node[n]){
            if(!visit[i])
                ret += DFS(i, node, visit);
        }
        return ret;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> node(n);
        vector<bool> visit(n, false);
        for(auto edge:edges){
            node[edge[0]].emplace_back(edge[1]);
            node[edge[1]].emplace_back(edge[0]);
        }
        for(auto i:restricted)
            visit[i] = true;
        return DFS(0, node, visit);
    }
};