#include<bits/stdc++.h>
using namespace std;

//数学法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        for(int i:nums)
            sum -= i;
        return sum;
    }
};