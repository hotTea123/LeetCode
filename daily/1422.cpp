#include<bits/stdc++.h>
using namespace std;

//2022.8.14 每日一题
class Solution {
public:
    int maxScore(string s) {
        int scorel = 0, scorer = 0;
        for(int i=1;i < s.size();i++){
            if(s[i] == '1')
                ++scorer;
        }
        if(s[0] == '0')
            ++scorel;
        int res = scorel + scorer;
        for(int i=1;i < s.size()-1;i++){
            if(s[i] == '0')
                ++scorel;
            else
                --scorer;
            res = max(res, scorel+scorer);
        }
        return res;
    }
};