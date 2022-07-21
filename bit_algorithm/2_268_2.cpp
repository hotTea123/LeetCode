#include<bits/stdc++.h>
using namespace std;

//异或的巧妙运用
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i=1;i < nums.size()+1;i++)
            sum = sum ^ i;
        for(int i=0;i < nums.size();i++)
            sum = sum ^ nums[i];
        return sum;
    }
};