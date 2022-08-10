#include<bits/stdc++.h>
using namespace std;

//使用一个set，因为nums中数据是严格递增的，因此不存在重复
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> s;
        for(int i=0;i < nums.size();i++)
            s.insert(nums[i]);
        int res = 0;
        for(int i=0;i < nums.size();i++){
            if(s.find(nums[i]+diff) != s.end() && s.find(nums[i]+2*diff) != s.end())
                ++res;
        }
        return res;
    }
};