#include<bits/stdc++.h>
using namespace std;

/*
    空间复杂度O(1)，将第0行和第0列用来存储各行和列是否为0
    只需要常数空间来存储第0行和第0列是否为0
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, column = false;
        for(int i=0;i <m;i++){
            if(matrix[i][0] == 0)
                row = true;
        }
        for(int i=0;i < n;i++){
            if(matrix[0][i] == 0)
                column = true;
        }
        for(int i=1;i < m;i++){
            for(int j=1;j < n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i < m;i++){
            for(int j=1;j <n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(row){
            for(int i=0;i < m;i++)
                matrix[i][0] = 0;
        }
        if(column){
            for(int i=0;i < n;i++)
                matrix[0][i] = 0;
        }
        
    }
};