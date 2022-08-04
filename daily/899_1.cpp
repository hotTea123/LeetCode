#include<bits/stdc++.h>
using namespace std;

/*
    当k>1的时候，最后的结果一定是一个升序字符串，考虑k=2，每次都可以对两个字符串做一个局部升序。
    当k=1时，只需要找到字符串中的最小子串，以它为字符串首，暴力的解法为O(n²)
*/
class Solution {
public:
    string orderlyQueue(string s, int k) {
        string res = "";
        if(k > 1){
            vector<int> cnt(26, 0);
            for(char c:s)
                ++cnt[c-'a'];
            for(int i=0;i < 26;i++){
                while(cnt[i] != 0){
                    res += i+'a';
                    --cnt[i];
                }
            }
        }else{
            //暴力
            int smallpos = 0;
            for(int i=1;i < s.size();i++){
                if(s[i] < s[smallpos])
                    smallpos = i;
                else if(s[i] > s[smallpos])
                    continue;
                else{
                    int m = smallpos, n = i;
                    int time = 0;
                    while(s[m] == s[n] && time < s.size()){
                        ++time;
                        m = (m+1)%s.size();
                        n = (n+1)%s.size();
                    }
                    if(s[m] > s[n])
                        smallpos = i;
                }
            }
            res += s.substr(smallpos);
            res += s.substr(0, smallpos);
        }
        return res;
    }
};