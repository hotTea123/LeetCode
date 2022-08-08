#include<bits/stdc++.h>
using namespace std;

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