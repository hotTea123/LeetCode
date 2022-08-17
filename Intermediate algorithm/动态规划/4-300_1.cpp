#include<bits/stdc++.h>
using namespace std;

/*
    动态规划的常规思路：dp[i]表示以nums[i]结尾的最长递增子序列
    时间复杂度O(n²)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); 
        int res = 1;
        for(int i=0;i < nums.size();i++){
            for(int j=0;j < i;j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};