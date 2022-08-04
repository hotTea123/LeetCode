#include<bits/stdc++.h>
using namespace std;

//  1.暴力解法，时间复杂度O(n²)
int naive(string& s){
    int n = s.size();
    int i=0, j=1, k=0;
    while(i<n && j<n && k<n){
        if(s[(i+k)%n] == s[(j+k)%n])
            ++k;
        else{
            if(s[(i+k)%n] > s[(j+k)%n])
                ++i;
            else
                ++j;
            k = 0;
            if(i == j)
                ++i;
        }
    }
    return min(i, j);
}

/*
    2.最小表示法,对上文暴力的优化
*/
int MinimalNotation(string& s){
    int n = s.size();
    int i=0, j=1, k=0;
    while(i<n && j<n && k<n){
        if(s[(i+k)%n] == s[(j+k)%n])
            ++k;
        else{
            if(s[(i+k)%n] > s[(j+k)%n])
                i = i+k+1;
            else
                j = j+k+1;
            k = 0;
            if(i == j)
                ++i;
        }
    }
    return min(i, j);
}