#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isFu(n, false);
        for(int i =0;i < n;i++){
            if(nums[i] < 0){
                nums[i] = -nums[i];
                isFu[i] = true;
            }
        }
        int vec1len = 0, vec2len = 0;
        int sum1 = 0, sum2 = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0;i < n;i++){
            if(vec1len == n/2){
                if(isFu[i])
                    sum1 += nums[i];
                else
                    sum2 += nums[i];
                continue;
            }else if(vec2len == n/2){
                if(isFu[i])
                    sum2 += nums[i];
                else
                    sum1 += nums[i];
                continue;
            }
            if(sum1 > sum2){
                sum2 += nums[i];
                if(isFu[i])
                    ++vec1len;
                else
                    ++vec2len;
            }else{
                sum1 += nums[i];
                if(isFu[i])
                    ++vec2len;
                else
                    ++vec1len;
            }
        }
        return abs(sum1-sum2);
    }
};

int main(){
    vector<int> nums = {36, -36};
    int res = Solution().minimumDifference(nums);
    return 0;
}