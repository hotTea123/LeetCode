#include<bits/stdc++.h>
using namespace std;

//需要排序，时间复杂度O(nlogn)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i < nums.size()-1;i += 2){
            if(nums[i] != nums[i+1])
                return nums[i];
        }
        return nums.back();
    }
};