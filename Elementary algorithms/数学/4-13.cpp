#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int pre = Roman[s[0]];
        int i=1, res = pre;
        while(i <s.size()){
            if(Roman[s[i]] > pre)
                res -= 2*pre;
            pre = Roman[s[i]];
            res += pre;
            ++i;
        }
        return res;
    }
};