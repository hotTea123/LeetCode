#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int longest = nums[0];
        for(int i=1;i < n;i++){
            if(i > longest)
                return false;
            longest = max(longest, i+nums[i]);
        }
        return true;
    }
};