#include<bits/stdc++.h>
using namespace std;

/*
    一种巧妙的动态规划思路，dp[i]表示长度为i的所有子序列中结尾最小的那个数
    比如 1，2，3，4  长度为3的子序列有[1,2,3]和[2,3,4]等，但dp[i] = 3
    并且这样的dp有一个很好的性质那就是当i<j时，dp[i]<dp[j](为什么)，即具有单调性，因此可以
  用二分更新dp
    为什么具有单调性：假设i<j时，dp[i] > dp[j],那么根据dp数组的定义，dp[j]所对应的那个子序列的
  倒数第二个数肯定<dp[j]<dp[i]，dp[i]应该被更新为倒数第二个数，因此不可能>dp[j]
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(1, nums[0]);
        for(int i=1;i < nums.size();i++){        
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(it == dp.end())
                dp.emplace_back(nums[i]);
            else
                *it = nums[i];
        }
        return dp.size();
    }
};