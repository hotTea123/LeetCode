#include<bits/stdc++.h>
using namespace std;

/*
    我的思路：2个数存放之前的递增数对，1个数存放更小的可能成为递增数对的数，按不同情况分类讨论更新这三个数
    但是，我们发现似乎没有必要，当递增数对的第二个数确定后，第一个数已经没有存在的必要了，因为只需要大于
  第二个数就能返回true，与第一个数无关，所以可以直接用第一个数才存放递增数对确定后出现的更小的数，那么情
  况就变成了如果num < low, 更新low，如果low < num < mid，更新mid，见5-334_2
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        bool flag = false;   //表示n是否有意义
        int m1 = INT_MAX-1, m2 = INT_MAX;
        int n1;
        for(int i=0;i < nums.size();i++){
            if(nums[i] > m2)
                return true;
            if(flag && nums[i] < n1){
                n1 = nums[i];
            }else if(flag && nums[i] < m2){
                if(nums[i] != n1){
                    m1= n1;
                    m2 = nums[i];
                    flag = false;
                }
            }else if(!flag && nums[i] < m1){
                n1 = nums[i];
                flag = true;
            }else if(!flag && nums[i] < m2){
                if(nums[i] != m1)
                    m2 = nums[i];
            }
        }
        return false;
    }
};