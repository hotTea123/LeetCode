#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(3);
        if(n == 1)
            return 1;
        dp[1] = 1;
        if(n == 2)
            return 2;
        dp[2] = 2;
        for(int i = 3;i <= n;i++){
            dp[2] = dp[0] + dp[1] + 2;
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};
int main(){
    Solution sovle;
    int n = 4;
    int res = sovle.climbStairs(n);
    return 0;
}