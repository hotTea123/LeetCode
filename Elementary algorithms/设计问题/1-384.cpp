#include<bits/stdc++.h>
using namespace std;

// 洗牌算法：每次从nums数组中拿一个元素，假设是i，拿完之后把最后一个元素放到i的位置，数组的长度-1
class Solution {
private:
    vector<int> nums;
    unsigned seed;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        seed = time(0);
        srand(seed);
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        int n = nums.size();
        vector<int> r = nums, randomNums(n);
        int sz = n;
        for(int i=0;i < n;i++){
            int j = rand() % sz;
            randomNums[i] = r[j];
            r[j] = r[n-i-1];
            --sz;
        }
        return randomNums;
    }
};