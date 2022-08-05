#include<bits/stdc++.h>
using namespace std;

/*
    先排序，使用双指针，第一个指针从0开始，每次与从最后开始的指针判断两个指针中间是否存在另一个加
  起来=0的数，指针移动时如果该数等于前一个数要跳过，时间复杂度为O(nlogn)
*/
class Solution {
private:
    bool findNum(vector<int>& nums, int low, int high, int val){
        int mid;
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == val)
                return true;
            if(nums[mid] < val)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sum(3);
        sort(nums.begin(), nums.end());
        for(int i=0;i < nums.size()-1;i++){
            if(i > 0&&nums[i] == nums[i-1])
                continue;
            for(int j=nums.size()-1;j > i+1;j--){
                if(j < nums.size()-1 && nums[j] == nums[j+1])
                    continue;
                if(nums[i]+nums[j]+nums[j-1] < 0)
                    break;
                if(findNum(nums, i+1, j-1, -nums[i]-nums[j])){
                    sum[0] = nums[i];
                    sum[1] = nums[j];
                    sum[2] = -nums[i]-nums[j];
                    res.emplace_back(sum);
                }
            }
        }
        return res;
    }
};