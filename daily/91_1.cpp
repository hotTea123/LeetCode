#include<vector>
#include<algorithm>
using namespace std;

/* **********
 * 算法思想：动态规划，dp[i][j]表示前i个房子以第j种颜色结尾的最少花费
    状态转移方程：dp[i][j] = dp[i-1][其他两种颜色]的最小花费+cost[i][j]
    初始条件：dp[0] = cost[0]
    最后结果：取dp.back()中的最小的值
 * 时间复杂度O(n), 空间复杂度O(n)
 * **********/


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int houseNum = costs.size();
        vector<vector<int>> dp;
        vector<int> temp(3);
        if(houseNum > 0){
            dp.emplace_back(costs[0]);
        }
        for(int i =1;i < houseNum;i++){
            temp[0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            temp[1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            temp[2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
            dp.emplace_back(temp);
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};

int main(){
    Solution sovle;
    vector<vector<int>> costs = {{17,2,17}, {16,16,5}, {14,3,19}};
    int m = sovle.minCost(costs);
    return 0;
}

