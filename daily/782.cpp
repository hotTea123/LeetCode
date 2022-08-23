#include<bits/stdc++.h>
using namespace std;

// 2022.8.23 每日一题
/*
    1.判断第一行0、1个数是否相差<=1
    2.如果第一行为demo，那么之后的每一行要么跟demo相同，要么跟demo完全相反才可能通过交换形成棋盘
    3.判断跟demo相同的行和相反的行是否相差<=1(demo也要算)
    4.计算需要交换的次数，首先判断是跟demo相同的行多还是相反的行多，或者一样多，并把每行的索引存入相应的数组；
      判断多的某种类型(跟demo相同或相反)的行的索引是否是偶数(多的类型最后应从0开始放置)，不是则交换次数+1；
      如果一样多，那么两种类型从0开始放置都要算一遍，取两者较小值
    5. 将broad按左对角线进行交换，重复1~4步骤。(也就是判断了列)
*/
class Solution {
private:
    void swapGrid(vector<vector<int>>& board){
        for(int i=0;i < board.size();i++){
            for(int j=0;j < board.size();j++){
                if(i == j)
                    break;
                swap(board[i][j], board[j][i]);
            }
        }
    }
    int findSwapTimes(vector<int>& idx){
        int ret = 0;
        for(int i=0;i < idx.size();i++){
            if(idx[i] % 2 != 0)
                ++ret;
        }
        return ret;
    }
    int exchangeTimes(vector<vector<int>>& board){
        int n = board.size();
        vector<int> demo(n);
        int cnt0 = 0, cnt1 = 0;
        for(int i=0;i < n;i++){
            demo[i] = board[0][i];
            if(demo[i] == 0)
                ++cnt0;
            else
                ++cnt1;
        }
        //每一行、列0/1的个数不超过2
        if(abs(cnt0-cnt1) > 1)
            return -1;
        vector<int> demoReverse(n);
        for(int i=0;i < n;i++){
            if(demo[i] == 0)
                demoReverse[i] = 1;
            else
                demoReverse[i] = 0;
        }
        vector<int> idx0, idx1;   //存放跟demo不一样的位置
        for(int i=0;i < n;i++){
            if(board[i] == demo)
                idx0.emplace_back(i);
            else if(board[i] == demoReverse)
                idx1.emplace_back(i);
            else
                return -1;
        }
        if(abs((int)(idx0.size()-idx1.size())) > 1)
            return -1;
        if(idx0.size() == idx1.size())
            return min(findSwapTimes(idx0), findSwapTimes(idx1));    
        else if(idx0.size() > idx1.size())
            return findSwapTimes(idx0); 
        else
            return findSwapTimes(idx1);
    }
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int res = 0, ret;
        ret = exchangeTimes(board);
        if(res == -1)
            return -1;
        res += ret;
        swapGrid(board);
        ret = exchangeTimes(board);
        if(ret == -1)
            return -1;
        res += ret;
        return res;
    }
};

int main(){
    vector<vector<int>> board = {{0,1}, {1,0}};
    int res = Solution().movesToChessboard(board);
    return 0;
}