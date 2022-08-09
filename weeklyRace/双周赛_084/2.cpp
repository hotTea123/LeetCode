#include<bits/stdc++.h>
using namespace std;

/*
    又是脑筋急转弯的题，用给定数组减去数组[1,2,3,4...,n]，如果减去后有k个数的值相同，则表示这k个数可组
  成好数组，坏数组+好数组=总的数组个数(n*(n-1)/2)
*/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int i=0;i < nums.size();i++){
            nums[i] -= i;
            ++cnt[nums[i]];
        }
        long long res = (long long)n*(n-1)/2;
        for(auto a:cnt){
            if(a.second != 1)
                res -= (long long)(a.second-1)*a.second/2;
        }
        return res;
    }
};