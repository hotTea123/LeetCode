#include<bits/stdc++.h>
using namespace std;

/*
    KMP:
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, k=0;
        while(i < haystack.size() && k < needle.size()){
            if(haystack[i+k] == needle[k])
                ++k;
            else{
                ++i;
                k=0;
            }
        }
        if(k == needle.size())
            return i;
        return -1;
    }
};