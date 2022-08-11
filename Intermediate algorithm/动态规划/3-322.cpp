#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i=1;i<amount+1;i++){
            int m = INT_MAX;
            for(int coin:coins){
                if(i <= coin){
                    if(i == coin)
                        dp[i] = 1;
                    break;
                }else{
                    if(dp[i-coin] != -1 && dp[i-coin] < m){
                        m = dp[i-coin];
                        dp[i] = m+1;
                    }
                }
            }
        }
        return dp.back();
    }
};