#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int maxNum = nums.back();
        for(int i=nums.size()-2;i >=0;i--){
            if(nums[i] > maxNum){
                int n = nums[i] / maxNum;
                if(nums[i] % maxNum != 0)
                    ++n;
                res += n-1;
                maxNum = nums[i] / n;
            }else
                maxNum = nums[i];
        }
        return res;
    }
};