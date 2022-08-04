#include<bits/stdc++.h>
using namespace std;

/*
    k<1，直接排序将s变成升序的
    k=1，采用最小表示法找到字符串中最小子串的位置(模板题)
*/
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        int n = s.size();
        int i=0, m=0, j=1;
        while(m < n && i < n && j < n){
            if(s[(i+m)%n] == s[(j+m)%n])
                ++m;
            else{
                if(s[(i+m)%n] > s[(j+m)%n])
                    i = i+m+1;
                else
                    j = j+m+1;
                m = 0;
                if (i == j) 
                    i++;
            }
        }
        i = min(i, j);
        return s.substr(i)+s.substr(0, i);
    }
};