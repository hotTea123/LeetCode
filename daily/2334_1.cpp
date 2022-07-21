#include<bits/stdc++.h>
using namespace std;

/*
    求一个数的最值区间，可用单调栈
    单调栈注意事项：1.遇到相同元素是否需要弹出
                2.出栈时机和入栈时机的具体含义
    思想方法：要解决这个问题可以通过求出以每个元素nums[i]为最小值的数组长度len，nums[i]/len>k即是满
    足条件的解，现在的问题变成了怎么求以每个元素nums[i]为最小值的数组长度。
    具体做法：将nums数组依次放入一个递增的单调栈(放入的是索引)，入栈的时候会一直弹出比该元素大或者等于
    该元素的值，直到不能弹出为止的那个索引所对应的值就是当前元素的左边界了(左边界开)，求右边界同理，将
    数组从后往前入栈，就可以得到以nums[i]为最小元素的左边界left和右边界right，right-left-1为长度。
    时间复杂度O(n)
*/
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        stack<int> monostack;
        vector<int> left(n, -1), right(n, n);
        
        for(int i=0;i<n;i++){
            while(!monostack.empty() && nums[i] <= nums[monostack.top()])
                monostack.pop();
            if(!monostack.empty())
                left[i] = monostack.top();
            monostack.push(i);
        }
        monostack = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!monostack.empty() && nums[i] <= nums[monostack.top()])
                monostack.pop();
            if(!monostack.empty())
                right[i] = monostack.top();
            monostack.push(i);
        }
        
        for(int i=0;i < n;i++){
            int len = right[i]-left[i]-1;
            if(nums[i] > threshold / len)
                return len;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {6,5,6,5,8};
    int threshold = 7;
    int res = Solution().validSubarraySize(nums, threshold);
    return 0;
}