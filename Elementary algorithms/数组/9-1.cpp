#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res(2);
        for(int i=0;i < nums.size();i++){
            if(hash.find(target-nums[i]) == hash.end())
                hash[nums[i]] = i;
            else{
                res[0] = i;
                res[1] = hash[target-nums[i]];
                break;
            }
        }
        return res;
    }
};