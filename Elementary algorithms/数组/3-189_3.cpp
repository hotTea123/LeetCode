#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, startPos = 0, i = 0, temp = nums[startPos];
        while(1){
            swap(temp, nums[(i+k)%n]);
            ++cnt;
            if(cnt == n)
                return;
            i = (i+k)%n;
            if(i == startPos){
                ++i;
                ++startPos;
                temp = nums[startPos];
            }
        }
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    Solution().rotate(nums, 3);
    return 0;
}