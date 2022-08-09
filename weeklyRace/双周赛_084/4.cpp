#include<bits/stdc++.h>
using namespace std;

/*
    贪心的题目，倒序遍历数组，假设前一个数是n，那么问题就变成了如何把一个数拆分成m个数，且这m个数都不
  大于n，但这m个数最小值要尽可能的大，然后就变成了一个数学问题
*/
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