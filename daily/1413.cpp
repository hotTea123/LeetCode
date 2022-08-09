#include<bits/stdc++.h>
using namespace std;

//2022.8.9每日一题
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int m = nums[0], sum = nums[0];
        for(int i=1;i < nums.size();i++){
            sum += nums[i];
            m = min(m, sum);
        }
        if(m >= 1)
            return 1;
        return 1-m;
    }
};