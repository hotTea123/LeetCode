#include<bits/stdc++.h>
using namespace std;

/*
    先上下交换，再对角线交换
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {\
        int n = matrix.size();
        int i=0, j=n-1;
        while(i < j){
            for(int k = 0;k < n;k++)
                swap(matrix[i][k], matrix[j][k]);
            ++i;
            --j;
        }

        for(i=0;i < n;i++){
            for(j=0;j < n;j++){
                if(i == j)
                    break;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};