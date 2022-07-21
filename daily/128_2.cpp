#include<bits/stdc++.h>
using namespace std;

//解法二：哈希表
/*
    思想方法：关键在于永远是从一段连续序列最小的数开始计算连续序列长度
    一段连续序列最小的数(假设为i)，即i-1不在这个序列中而i在
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se;  //以某一个数为结尾的最长数字连续序列
        for(int i = 0;i < nums.size();i++)
            se.insert(nums[i]);
        int res = 0;
        for(int i:se){
            if(se.find(i-1) != se.end())
                continue;
            int n = i+1;
            while(se.find(n) != se.end())
                ++n;
            res = max(res, n-i);
        }
        return res;
    }
};