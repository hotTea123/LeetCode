#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i]表示以第i个元素结尾的最大子序和
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++)
            dp[i] = max(dp[i-1]+nums[i], nums[i]);

        int res = dp[0];
        for(int i:dp)
            res = (i>res) ? i:res;
        return res;
    }
};