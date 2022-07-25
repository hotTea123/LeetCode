#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(2,0);
        int res = 0;
        for(int i=0;i < nums.size();i++){
            res = max(dp[0]+nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = res;
        }
        return max(dp[0], dp[1]);
    }
};