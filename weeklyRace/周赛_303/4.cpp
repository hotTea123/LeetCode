#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int computeCnt(int x){
        int ret = 0;
        while(x > 0){
            x &= ~(x & (-x));
            ++ret;
        }
        return ret;
    }
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);
        unordered_map<int, int> times;  //某个数是否出现过
        long long res = 0;
        for(int n:nums){
            times[n]++;
            if(times[n] == 1)
                cnt[computeCnt(n)]++;
        }

        vector<int> dp(32);   //dp[i]表示第i个位置到末尾的和
        dp[31] = cnt[31];
        for(int i=30;i >=0;i--)
            dp[i] = dp[i+1]+cnt[i];
        
        for(int i=0;i < 32;i++){
            if(i >= k)
                res += dp[0]*cnt[i];
            else{
                if(k-i < 32)
                res += cnt[i]*dp[k-i];
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3,1,536870911};
    long long res = Solution().countExcellentPairs(nums,3);
    return 0;
}