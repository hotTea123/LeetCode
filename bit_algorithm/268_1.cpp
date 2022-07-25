#include<bits/stdc++.h>
using namespace std;

//需要排序，时间复杂度O(nlogn)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = 0;
        for(int i=0;i < nums.size();i++){
            if(nums[i] != n)
                return n;
            ++n;
        }
        return n;
    }
};