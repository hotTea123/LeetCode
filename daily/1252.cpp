#include<bits/stdc++.h>
using namespace std;

//简单题，有一些优化的加速时间和减小空间的技巧可以看看
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i=0;i < indices.size();i++){
            int row = indices[i][0], col =indices[i][1];
            for(int j=0;j < n;j++)
                ++grid[row][j];
            for(int j=0;j < m;j++)
                ++grid[j][col];
        }
        int res = 0;
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++)
                if(grid[i][j] % 2 != 0)
                    ++res;
        }
        return res;
    }
};