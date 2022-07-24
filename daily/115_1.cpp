#include<bits/stdc++.h>
using namespace std;

/*
    思路1：只要sequences里面能拿到nums中每个数字的偏序关系，则一定能得到唯一的nums
    用一个n+1大小的vector存每个数字i的下一个数字(即规定他们的偏序关系)，再遍历sequences找是否存在那样
  的偏序关系，用bool标志是否在sequences中找到了某个数字的偏序关系，只有nums中所有数字都是bool才能返回
  成功
*/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> numbers(n+1);
        for(int i=0;i < nums.size()-1;i++){
            numbers[nums[i]] = nums[i+1]; 
        }
        vector<bool> exist(n+1);
        exist[0] = true;
        exist[nums.back()] = true;
        for(auto sequence:sequences){
            for(int i=0;i < sequence.size()-1;i++){
                if(sequence[i+1] == numbers[sequence[i]]){
                    exist[sequence[i]] = true;
                }
            }
        }
        for(auto i:exist){
            if(i == false)
                return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> sequences = {{1,2},{1,3},{2,3}};
    bool res = Solution().sequenceReconstruction(nums, sequences);
    return 0;
}