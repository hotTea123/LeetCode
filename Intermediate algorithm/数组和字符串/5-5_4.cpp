#include<bits/stdc++.h>
using namespace std;

//动态规划，空间复杂度优化至O(n)
class Solution {
public:
    string longestPalindrome(string s) {
        vector<bool> dp(s.size(), 0);
        int maxlen = 0;
        pair<int, int> sub;
        for(int i=s.size()-1;i >= 0;i--){
            for(int j=s.size()-1;j >=i;j--){
                if(j == i || (j == i+1 && s[i] == s[j]) || (dp[j-1] && s[i] == s[j]))
                    dp[j] = 1;
                else
                    dp[j] = 0;
                if(dp[j] && j-i+1 > maxlen){
                    maxlen = j-i+1;
                    sub = make_pair(i, maxlen);
                }
            }
        }
        return s.substr(sub.first, sub.second);
    }
};


int main(){
    string s = "babad";
    string res = Solution().longestPalindrome(s);
    return 0;
}