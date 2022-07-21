#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int w = m*n;
        k %= w;
        if(k == 0)
            return grid;
        vector<int> nums(w);
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                nums[i*n+j] = grid[i][j];
            }
        }

        int s = w-k;
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                grid[i][j] = nums[s];
                s = (s + 1) % w;
            }
        }
        return grid;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    Solution().shiftGrid(grid, 1);
    return 0;
}