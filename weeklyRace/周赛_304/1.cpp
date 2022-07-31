#include<bits/stdc++.h>
using namespace std;

//简单模拟题
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minNum = *max_element(nums.begin(), nums.end());
        int res = 0;
        while(minNum != 0){
            for(int i=0;i < nums.size();i++){
                if(nums[i] != 0)
                    minNum = min(nums[i], minNum);
            }
            for(int i=0;i < nums.size();i++){
                if(nums[i] != 0)
                    nums[i] -= minNum;
            }
            ++res;
            minNum = *max_element(nums.begin(), nums.end());
        }
        return res;
    }
};