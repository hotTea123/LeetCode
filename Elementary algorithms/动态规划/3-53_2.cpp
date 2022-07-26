#include<bits/stdc++.h>
using namespace std;

//dp在空间上的优化(滚动dp)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i]表示以第i个元素结尾的最大子序和
        int dp = nums[0], res = dp;
        for(int i=1;i<nums.size();i++){
            dp = nums[i]+max(dp,0);
            res = dp > res ? dp:res;
        }
        return res;
    };
};