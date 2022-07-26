#include<vector>
#include<algorithm>
using namespace std;

/* **********
 * 算法思想：在1的基础上优化空间复杂度，由于dp[i]只跟dp[i-1]有关，因此可以使用一个滚动数组temp优化空间
 * 时间复杂度O(n), 空间复杂度O(1)
 * **********/


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int houseNum = costs.size();
        vector<int> dp(3), temp(3);
        dp = costs[0];
        for(int i =1;i < houseNum;i++){
            temp[0] = min(dp[1], dp[2]) + costs[i][0];
            temp[1] = min(dp[0], dp[2]) + costs[i][1];
            temp[2] = min(dp[0], dp[1]) + costs[i][2];
            dp = temp;
        }
        return min(min(dp[0], dp[1]), dp[2]);
    }
};

int main(){
    Solution sovle;
    vector<vector<int>> costs = {{17,2,17}, {16,16,5}, {14,3,19}};
    int m = sovle.minCost(costs);
    return 0;
}