#include<bits/stdc++.h>
using namespace std;

//时隔1个月后重新写的代码
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = "", temp;
        bool flag = false;
        while(n > 0){
            s = to_string(n%10) + s;
            n = n /10;
            temp = s;
            sort(temp.begin(), temp.end(), greater<char>());
            if(temp != s){
                flag = true;
                break;
            }
        }
        if(!flag)
            return -1;
        long long res = n;
        for(int i=s.size()-1;i > 0;i--){
            if(s[i] > s[0]){
                swap(s[i], s[0]);
                sort(s.begin()+1, s.end());
                break;
            }
        }
        for(int i=0;i < s.size();i++){
            res *= 10;
            res += (int)s[i];
            if(res > INT_MAX)
                return -1;
        }
        return res;

    }
};