#include<bits/stdc++.h>
using namespace std;

/*
    1.横向比较：所有字符串进行两两比较，如果遇到""直接返回
    2.纵向比较：比较每个字符串的第i个字符是否相等
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        string res = "";
        bool isEnd = false;
        while(1){
            char temp = '0';
            for(int j=0;j<strs.size();j++){
                if(strs[j].size() == 0)
                    return "";
                if(temp == '0')
                    temp = strs[j][i];
                if(strs[j][i] != temp)
                    return res;
                if(i == strs[j].size()-1)
                    isEnd = true;
            }
            res += temp;
            ++i;
            if(isEnd)
                break;
        }
        return res;
    }
};