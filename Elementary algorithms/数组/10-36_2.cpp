#include<bits/stdc++.h>
using namespace std;

/*
    1次遍历,空间换时间，使用3个9×9的数组分别存储不同行/列/3×3的盒子的数排列情况
    对于(i, j)而言，其处于第i/3*3+j/3个盒子
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool hang[9][9] = {false};
        bool lie[9][9] = {false};
        bool box[9][9] = {false};
        for(int i=0;i < 9;i++){
            for(int j=0;j < 9;j++){
                if(board[i][j] == '.')
                    continue;
                if(hang[i][board[i][j]-'0'-1])
                    return false;
                hang[i][board[i][j]-'0'-1] = true;
                if(lie[j][board[i][j]-'0'-1])
                    return false;
                lie[j][board[i][j]-'0'-1] = true;
                if(box[(i/3)*3+j/3][board[i][j]-'0'-1])
                    return false;
                box[(i/3)*3+j/3][board[i][j]-'0'-1] = true;
            }
        }
        return true;
    }
};