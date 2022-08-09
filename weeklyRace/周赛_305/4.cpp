#include<bits/stdc++.h>
using namespace std;

//动态规划，使用一个26大小的数组表示以某个英文字母结尾的最长理想字符串
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> cnt(26, 0);
        for(char ch:s){
            int letter = ch - 'a', longest = 0;
            for(int i=max(0, letter-k);i <= min(letter+k, 25);i++){
                longest = max(cnt[i], longest);
            }
            cnt[letter] = longest + 1;
        }
        int res = 0;
        for(auto i:cnt)
            res = max(res, i);
        return res;
    }
};