#include<bits/stdc++.h>
using namespace std;

//使用位运算的技巧，时间复杂度O(n)
//异或的经典运用
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i:nums)
            sum ^= i;
        return sum;
    }
};