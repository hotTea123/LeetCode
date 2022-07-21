#include<bits/stdc++.h>
using namespace std;

//常规哈希表写法，空间复杂度O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i:nums)
            count[i]++;
        for(auto [a, b]:count){
            if(b == 1)
                return a;
        }
        return 0;
    }
};