#include<bits/stdc++.h>
using namespace std;

//中心扩散法，优化
class Solution {
public:
    string longestPalindrome(string s) {
        int l, r;
        int i=0, maxlen = 0;
        pair<int, int> res;
        while(i < s.size()){
            l = i, r=i;
            while(r < s.size()-1 && s[r+1] == s[l])
                ++r;
            i = r;
            while(l >= 0 && r < s.size() && s[r] == s[l]){
                --l;
                ++r;
            }
            if(r-l-1 > maxlen){
                maxlen = r-l-1;
                res = make_pair(l+1, maxlen);
            }
            ++i;
        }
        return s.substr(res.first, res.second);
    }
};