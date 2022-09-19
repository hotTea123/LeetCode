#include <bits/stdc++.h>
using namespace std;

// 2022.9.12 每日一题
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        if(n <= nums[0])
            return n;
        for(int i=0;i < n;i++){
            if(i > 0 && nums[i-1] < n-i && nums[i] >= n-i)
                return n-i;
            if(nums[i] > n-i)
                break;
        }
        return -1;
    }
};
