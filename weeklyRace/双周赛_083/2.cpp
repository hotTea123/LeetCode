#include<bits/stdc++.h>
using namespace std;

//出错竟然是因为没有把cnt的类型设置为long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        for(int i=0;i < nums.size();i++){
            long long cnt = 0;
            while(i < nums.size() && nums[i] == 0){
                ++cnt;
                ++i;
            }
            res += (1+cnt)*cnt/2;   //这一步的时候乘法可能已经爆掉了，但是还默认是int类型(如果cnt是int类型)
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0,1,0,0,1,0,0,0};
    long long res = Solution().zeroFilledSubarray(nums);
    return 0;
}