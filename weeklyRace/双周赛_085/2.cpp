#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool changeChar(string& s){
        int i=1;
        bool flag = false;
        while(i < s.size()){
            if(s[i-1] == '0' && s[i] == '1'){
                swap(s[i-1], s[i]);
                flag = true;
                i += 2;
            }else
                ++i;
        }
        return flag;
    }
public:
    int secondsToRemoveOccurrences(string s) {
        int res = 0;
        while(changeChar(s))
            ++res;
        return res;
    }
};