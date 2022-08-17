#include<bits/stdc++.h>
using namespace std;

// 算法库中有用vector实现的堆，注意pop_heap后需要手动在vector中进行pop_back真正移除那个元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        while(k > 1){
            --k;
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums[0];
    }
};