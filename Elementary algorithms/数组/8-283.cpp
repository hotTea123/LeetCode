#include<bits/stdc++.h>
using namespace std;

//双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=1;
        while(j < nums.size()){
            if(nums[i] == 0){
                while(j < nums.size() && nums[j] == 0)
                    ++j;
                if(j == nums.size())
                    return;
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            }else
                ++i;
            if(j <= i)
                j = i+1;
        }
    }
};