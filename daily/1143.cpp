#include<bits/stdc++.h>
using namespace std;

/*
    思路：dp[i][j]表示第一个字符串以i结尾和第二个字符串以j结尾所构成的最长公共子序列
    转移方程：
        if(s1[i] == s2[j])   dp[i][j] = dp[i-1][j-1]+1
        if(s1[i] != s2[j])   dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    dp的初始化技巧：可设置大一维的数组，但是在使用s1/s2的角标的时候要注意是s1[i-1]
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.size(), sz2 = text2.size();
        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));

        //定义大一维的数组可避免下面的初始化代码
        // dp[0][0] = (text1[0] == text2[0]) ? 1 : 0;
        // for(int i=1;i < sz1;i++){
        //     dp[i][0] = dp[i-1][0];
        //     if(text1[i] == text2[0])
        //         dp[i][0] = 1;
        // }
        // for(int i=1;i < sz2;i++){
        //     dp[0][i] = dp[0][i-1];
        //     if(text2[i] == text1[0])
        //         dp[0][i] = 1;
        // }

        for(int i=1;i <= sz1;i++){
            for(int j=1;j <= sz2;j++){
                if(text1[i-1] == text2[j-1])   //最开始出错在这
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[sz1][sz2];
    }
};

int main(){
    string s1 = "ab", s2 = "de";
    int res = Solution().longestCommonSubsequence(s1, s2);
    return 0;
}