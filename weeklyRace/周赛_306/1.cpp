#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findmax(int m, int n, vector<vector<int>>& grid){
        int ret = 0;
        for(int i=m;i < m+3;i++){
            for(int j=n;j < n+3;j++){
                ret = max(ret, grid[i][j]);
            }
        }
        return ret;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m-2, vector<int>(n-2));
        for(int i=0;i < m-2;i++){
            for(int j=0;j < n-2;j++){
                res[i][j] = findmax(i, j, grid);
            }
        }
        return res;
    }
};