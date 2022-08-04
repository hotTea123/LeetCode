#include<bits/stdc++.h>
using namespace std;

/*
    三次遍历
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> visit(9);
        for(int i=0;i<9;i++){
            fill(visit.begin(), visit.end(), false);
            for(int j=0;j < 9;j++){
                if(board[i][j] != '.'){
                    if(visit[board[i][j]-'0'-1]){
                        return false;
                    }
                    visit[board[i][j]-'0'-1] = true;
                }
            }
        }

        for(int i=0;i<9;i++){
            fill(visit.begin(), visit.end(), false);
            for(int j=0;j < 9;j++){
                if(board[j][i] != '.'){
                    if(visit[board[j][i]-'0'-1])
                        return false;
                    visit[board[j][i]-'0'-1] = true;
                }
            }
        }

        for(int i=0;i < 9;i += 3){
            for(int j=0;j < 9;j += 3){
                fill(visit.begin(), visit.end(), false);
                for(int m = i;m < i+3;m++){
                    for(int n=j;n < j+3;n++){
                        if(board[m][n] != '.'){
                            if(visit[board[m][n]-'0'-1])
                                return false;
                            visit[board[m][n]-'0'-1] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};