#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> count;
        int res = -1;
        for(int num:nums){
            int sum = 0, n = num;
            while(n > 0){
                sum += n % 10;
                n /= 10;
            }
            if(count[sum].size() == 2){
                if(count[sum][0] < count[sum][1]){
                    count[sum][0] = num;
                }else{
                    count[sum][1] = num;
                }
            }else
                count[sum].emplace_back(num);
            if(count[sum].size() == 2){
                if(count[sum][0] + count[sum][1] > res)
                    res = count[sum][0] + count[sum][1];
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {18,43,36,13,7};
    int res = Solution().maximumSum(nums);
    return 0;
}