#include<bits/stdc++.h>
using namespace std;

//两个指针指向0/1边界和1/2边界，遍历数组，遇到0就放到0/1边界上，遇到2就放到1/2边界上
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m = 0, n = nums.size()-1;   //指向边界
        while(n >= 0 && nums[n] == 2)
            --n;
        while(m < nums.size() && nums[m] == 0)
            ++m;
        int i = m;
        while(i <= n){
            if(nums[i] == 0){
                swap(nums[i], nums[m]);
                ++m;
                ++i;
            }else if(nums[i] == 2){
                swap(nums[i], nums[n]);
                --n;
            }else
                ++i;
        }
    }
};