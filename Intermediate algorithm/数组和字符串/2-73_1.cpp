#include<bits/stdc++.h>
using namespace std;

/*
    空间复杂度O(m+n)，使用了两个额外的数组存储行和列是否为0
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> hang(m, false);
        vector<bool> lie(n, false);
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(matrix[i][j] == 0){
                    hang[i] = true;
                    lie[j] = true;
                }
            }
        }

        for(int i=0;i < m;i++){
            for(int j=0;j <n;j++){
                if(hang[i] || lie[j])
                    matrix[i][j] = 0;
            }
        }
    }
};