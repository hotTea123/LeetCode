#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<int>> result(n, vector<int>(n));
        vector<int> r(n);
        int t = 0;
        for(int j=0;j < n;j++){
            int k=0;
            for(int i=0;i < n;i++){
                r[k] = grid[i][j];
                k++;
            }
            result[t] = r;
            ++t;
        }      
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i] == result[j])
                    ++res;
            } 
        }
        return res;
    }
};

int main(){
    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    int res = Solution().equalPairs(grid);
    return 0;
}