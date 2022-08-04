#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char i:s){
            if(i >= 'A' && i <= 'Z')
                str += i+32;
            else if(i >= 'a' && i <= 'z')
                str += i;
            else if(i >= '0' && i <= '9')
                str += i;
        }
        int i = 0, j = str.size()-1;
        while(i < j){
            if(str[i] != str[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};