#include<bits/stdc++.h>
using namespace std;

// 2022.8.26 每日一题
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};