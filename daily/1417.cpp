#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool classify(char ch){
        if(ch >= '0' && ch <= '9')
            return 0;
        return 1;
    }
public:
    string reformat(string s) {
        int n = s.size();
        if(n == 1)
            return s;
        sort(s.begin(), s.end());
        int j;
        bool flag = false;
        if(classify(s[n/2]) && !classify(s[n/2-1]))
            j = n/2;
        else if(!classify(s[n/2]) && n > 2 && classify(s[n/2+1]))
            j = n/2+1;
        else
            return "";
        if((n / 2) & 1)
            flag = 1;
        int i = j-1;
        while(i >= 0 && j < n){
            if(flag)
                swap(s[i], s[j]);
            flag = !flag;
            ++j;
            --i;
        }
        return s;
    }
};