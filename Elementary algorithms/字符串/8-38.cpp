
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string describeNum(string s){
        int cnt = 1;
        char pre = s[0];
        string ret = "";
        for(int i=1; i< s.size();i++){
            if(pre == s[i])
                ++cnt;
            else{
                ret += cnt+'0';
                ret += pre;
                pre = s[i];
                cnt = 1;
            }
        }
        if(cnt){
            ret += cnt+'0';
            ret += pre;
        }
        return ret;
    }
public:
    string countAndSay(int n) {
        string cas = "1";
        for(int i=1;i<n;i++)
            cas = describeNum(cas);
        return cas;
    }
};