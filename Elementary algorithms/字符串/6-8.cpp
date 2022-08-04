#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long res = 0;
        while(s[i] == ' ')
            ++i;
        if(s[i] == '-'){
            ++i;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                if(res == 0){
                    res = -s[i]+'0';
                    ++i;
                    continue;
                }
                res = 10*res - (s[i]-'0');
                if(res < INT_MIN)
                    return INT_MIN;
                ++i;
            }
            return res;
        }
        if(s[i] == '+')
            ++i;
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            if(res == 0){
                res = s[i]-'0';
                ++i;
                continue;
            }
            res = 10*res + (s[i]-'0');
            if(res > INT_MAX)
                return INT_MAX;
            ++i;
        }
        return res;
    }
};