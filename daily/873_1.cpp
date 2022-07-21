#include<bits/stdc++.h>
using namespace std;

//比较常规的dp思路，时间复杂度O(n²logn)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int arrlen=arr.size(), res=0;
        vector<vector<int>> dp(arrlen, vector<int>(arrlen, 0));
        for(int i=1;i < arrlen;i++){
            for(int j=0;j<i;j++){
                int dif = arr[i] - arr[j];
                auto pos = lower_bound(arr.begin(), arr.begin()+j, dif);
                if(pos != arr.begin()+j && *pos == dif){
                    if(dp[pos-arr.begin()][j]==0)
                        dp[j][i] = 2;
                    dp[j][i] += dp[pos-arr.begin()][j] + 1;
                    if(dp[j][i] > res)
                        res = dp[j][i];
                }
            }
        }
        return res;
    }
};
