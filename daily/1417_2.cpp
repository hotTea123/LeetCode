#include<bits/stdc++.h>
using namespace std;

/*
    更加优雅的实现，双指针，但是不是在原字符串上双指针，是在新的字符串上做双指针，一个指针指向数字位，
  一个指针指向字母位，然后每次挪动指针只需要+2就可以，因为+2的位置还是原来类型的字符
*/
class Solution {
public:
    string reformat(string s) {
        int nums = 0, letters = 0;
        for(char ch:s){
            if(ch >= '0' && ch <= '9')
                ++nums;
            else
                ++letters;
        }
        if(abs(nums-letters) > 1)
            return "";
        int i = 0, j= 1;
        bool flag = true;
        if(nums > letters){
            j = 0;
            i = 1;
        }
        string res;
        res.resize(s.size());
        for(char ch:s){
            if(ch >= '0' && ch <= '9'){
                res[j] = ch;
                j += 2;
            }else{
                res[i] = ch;
                i += 2;
            }
        }
        return res;
    }
};