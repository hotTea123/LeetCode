#include<bits/stdc++.h>
using namespace std;

/*
    先排序，再使用三指针，i从0~n-1，j从i+1开始加，k从n-1开始减直到j与k相遇
    其中，如果nums[i]>0则永远不可能有满足条件的就结束了，因为nums[i]是最小的那个数了
    时间复杂度O(n²)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sum(3);
        sort(nums.begin(), nums.end());
        for(int i=0;i < nums.size()-2;i++){
            if(nums[i] > 0)
                break;
            if(i > 0&&nums[i] == nums[i-1])
                continue;
            int j=i+1, k=nums.size()-1;
            while(j < k){
                if(k < nums.size()-1 && nums[k] == nums[k+1]){
                    --k;
                    continue;
                }
                if(nums[i]+nums[k-1]+nums[k] < 0)
                    break;
                if(nums[i]+nums[j]+nums[k] == 0){
                    sum[0] = nums[i];
                    sum[1] = nums[j];
                    sum[2] = nums[k];
                    res.emplace_back(sum);
                    ++j;
                    --k;
                }else if(nums[i]+nums[j]+nums[k] < 0)
                    ++j;
                else
                    --k;   
            }
        }
        return res;
    }
};