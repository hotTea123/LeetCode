#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int longestPos = 0, longestLen = 0;
        bool isOdd = false;  //偶数为true
        string res = "";
        for(int i=0;i<s.size();i++){
            int j=1;
            while(i-j>=0 && i+j < s.size()){
                if(s[i-j] != s[i+j])
                    break;
                ++j;
            }
            if(j-1 > longestLen){
                longestLen = j-1;
                longestPos = i;
                isOdd = false;
            }
            j = 0;
            while(i-j>=0 && i+j+1 < s.size()){
                if(s[i-j] != s[i+j+1])
                    break;
                ++j;
            }
            if(j-1 >= longestLen){
                longestLen = j-1;
                longestPos = i;
                isOdd = true;
            }
        }
        int ansNum = 2*longestLen+1;
        if(isOdd)
            ++ansNum;
        return s.substr(longestPos-longestLen, ansNum);
    }
};