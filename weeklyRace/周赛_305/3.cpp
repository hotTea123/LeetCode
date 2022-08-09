#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;   //-1表示未初始化，0表示不是，1表示是 
    int isequal(vector<int>& nums, int l, int r){
        if(l > r)
            return 1;
        if(l == r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        if(nums[l] == nums[l+1]){
            if(l+2 > r)
                return 1;
            if(dp[l+2][r] == -1)
                dp[l+2][r] = isequal(nums, l+2, r);
            if(dp[l+2][r] == 1){
                dp[l][r] == 1;
                return 1;
            }
            if(r-l > 1 && nums[l] == nums[l+2]){
                if(l+3 > r)
                    return 1;
                if(dp[l+3][r] == -1)
                    dp[l+3][r] = isequal(nums, l+3, r);
                if(dp[l+3][r] == 1){
                    dp[l][r] == 1;
                    return 1;
                }
            }
        }
        if(r-l > 1 && nums[l]+1 == nums[l+1] && nums[l]+2 == nums[l+2]){
            if(l+3 > r)
                return 1;
            if(dp[l+3][r] == -1)
                dp[l+3][r] = isequal(nums, l+3, r);
            if(dp[l+3][r] == 1){
                dp[l][r] == 1;
                return 1;
            }
        }
        return 0;
    }
public:
    bool validPartition(vector<int>& nums) {
        dp.resize(nums.size(), vector<int>(nums.size(), -1));
        if(isequal(nums, 0, nums.size()-1) == 0)
            return false;
        return true;
    }
};

int main(){
    //vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,2,2,2,3,3,3,4,5,6,7,8,9};
    vector<int> nums = {1,1,1,2};
    //vector<int> nums = {4,4,4,5,6};
    bool res = Solution().validPartition(nums);
    return 0;
}