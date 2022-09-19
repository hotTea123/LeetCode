#include <bits/stdc++.h>
using namespace std;

// 2022.9.3 每日一题
// 常规dp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort(pairs.begin(), pairs.end(), [](vector<int> x, vector<int> y){
        //     if(x[0] == y[0])
        //         return x[1] < y[1];
        //     return x[0] < y[0];
        // });
        sort(pairs.begin(), pairs.end());   //默认会先比较第一个，第一个一样比较第二个
        vector<int> dp(pairs.size(), 1);
        int res = 0;
        for(int i=0;i < pairs.size();i++){
            for(int j=0;j < i;j++){
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> pairs = {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
    int res = Solution().findLongestChain(pairs);
    return 0;
}