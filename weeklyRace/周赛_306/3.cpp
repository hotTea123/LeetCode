#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        int num = 1;
        string res = "";
        string temp = "";
        for(char ch:pattern){
            temp = to_string(num) + temp;
            ++num;
            if(ch == 'I'){
                res += temp;
                temp = "";
            }
        }
        temp = to_string(num) + temp;
        res += temp;
        return res;
    }
};