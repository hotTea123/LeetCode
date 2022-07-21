#include<bits/stdc++.h>
using namespace std;

//BFS
class Solution {
private:
    int BFS(vector<vector<int>>& grid, int x, int y){
        int count = 0;
        queue<pair<int,int>> que;
        que.push(make_pair(x, y));
        while(!que.empty()){
            auto [i, j] = que.front();
            que.pop();
            if(grid[i][j] == 0)
                continue;
            count++;
            grid[i][j] = 0;
            if(i < grid.size()-1 && grid[i+1][j] == 1)
                que.push(make_pair(i+1, j));
            if(j < grid[0].size()-1 && grid[i][j+1] == 1)
                que.push(make_pair(i, j+1));
            if(i > 0 && grid[i-1][j] == 1)
                que.push(make_pair(i-1, j));
            if(j > 0 && grid[i][j-1] == 1)
                que.push(make_pair(i, j-1));
        }
        return count;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    res = max(res, BFS(grid, i, j));
            }
        }
        return res;
    }
};