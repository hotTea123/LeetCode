#include<bits/stdc++.h>
using namespace std;

/*
    我的思路：企图用两次dp完成，并且在用一个二维vector存储到达[i, j]的路径，在到达[N-1, N-1]的时候
    得到最大的摘樱桃数目和路径，修改grid，在用dp遍历回去。
    但是有一个问题！！！过去的时候摘樱桃的最大数目的路径是否是最终答案的路径？我觉得是的。
    结果不是。。。比如：
    0 1 -1 1
    1 0 -1 1
    1 1  1 1
    1 0  1 1

    正确思路：一来一回摘樱桃可以看成是两个人一起开始从起点到终点摘樱桃，可以用(x1,y1),(x2,y2)表示他们
    的坐标，然后dp,有一点需要注意的是，x1+y1=x2+y2=k，因为他们摘樱桃的速度是一样的，因此可以用一个三维
    dp[x1][x2][k]，通过k就能计算出y1和y2的坐标(降维)，初始时把所有位置都置为-1(一定是置为-1不是0，因为
    在做max运算的时候有可能会取到一些无效值，都置为-1则可直接表示不可达)
    转移：四种转移，两个人都从左边到达当前位置，都从上面，A从上B从左，B从上A从左(可以剪枝，因为A、B具有
    可交换性)，再加上各自当前位置的樱桃数，如果在同一位置则只加一次
    特别注意：1.边界条件的处理，x1、x2的取值范围，不然会导致数组溢出
            2.取到无效值(A、B从一些无效的地方转移过来)，在最初置dp数组为-1的情况下可以解决这一问题

----------------------错误代码----------------------------
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N ,0));
        //上面转移为false，左边转移为true
        vector<vector<bool>> path(N, vector<bool>(N));
        path[0][0] = false;
        for(int i=0;i < N;i++){
            for(int j=0;j < N;j++){
                int up = -1, left = -1;
                if(i > 0)
                    up = dp[i-1][j];
                if(j > 0)
                    left = dp[i][j-1];

                if(grid[i][j] == -1 || (up == -1 && left == -1)){
                    if(i == 0 && j == 0)
                        dp[i][j] = grid[i][j];
                    else
                        dp[i][j] = -1;
                    continue;
                }
                dp[i][j] = grid[i][j];
                if(up > left){
                    dp[i][j] += up;
                    path[i][j] = false;
                }else{
                    dp[i][j] += left;
                    path[i][j] = true;
                }
            }
        }
        //更新樱桃地
        int i=N-1, j=N-1;
        while(i != 0 || j != 0){
            if(grid[i][j] == 1)
                grid[i][j] = 0;
            if(path[i][j])
                --j;
            else
                --i;
        }
        //返回起点
        int res = dp[N-1][N-1];
        cout << "res1 = " << res << endl;
        for(i=N-1;i >= 0;i--){
            for(j=N-1;j >= 0;j--){
                int down = -1, right = -1;
                if(i < N-1)
                    down = dp[i+1][j];
                if(j < N-1)
                    right = dp[i][j+1];

                if(grid[i][j] == -1 || (down == -1 && right == -1)){
                    if(i == N-1 && j == N-1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = -1;
                    continue;
                }
                dp[i][j] = grid[i][j];
                if(down > right)
                    dp[i][j] += down;
                else
                    dp[i][j] += right;
            }
        }
        res += dp[0][0];
        return res;
    }
};
---------------------------------------------------
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2*N-1, -1)));
        //初始化
        dp[0][0][0] = grid[0][0];
        for(int k=1;k < 2*N-1;k++){
            for(int i=0;i < N && i <= k;i++){
                if(k-i >= N || grid[i][k-i] == -1)
                    continue;
                for(int j=0;j < N && j <= k && j <= i;j++){
                    if(k-j >= N || grid[j][k-j] == -1)
                        continue;
                    if(i != k && j != k)
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                    if(i != 0 && j!= 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1]);
                    if(i != 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                    if(j != 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    
                    if(dp[i][j][k] == -1)
                        continue;
                    if(i == j)
                        dp[i][j][k] += grid[i][k-i];
                    else
                        dp[i][j][k] += grid[i][k-i] + grid[j][k-j];
                }
            }
        }
        return max(dp[N-1][N-1][2*N-2], 0);
    }
};


int main(){
    //vector<vector<int>> grid = {{0,1,-1,1},{1,0,-1,1},{1,1,1,1},{1,0,1,1}};
    vector<vector<int>> grid = {{0, 1, -1},{1, 0, -1},{1, 1, 1}};
    int res = Solution().cherryPickup(grid);
    return 0;
}