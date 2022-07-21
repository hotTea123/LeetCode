#include<bits/stdc++.h>
using namespace std;

//DFS
class Solution {
private:
    int DFS(vector<vector<int>>& grid, int x, int y){
        if(grid[x][y] != 1)
            return 0;
        grid[x][y] = -1;
        int count = 1;
        if(x < grid.size()-1)
            count += DFS(grid, x+1, y);
        if(y < grid[0].size()-1)
            count += DFS(grid, x, y+1);
        if(x > 0)
            count += DFS(grid, x-1, y);
        if(y > 0)
            count += DFS(grid, x, y-1);
        return count;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    res = max(res, DFS(grid, i, j));
            }
        }
        return res;
    }
};