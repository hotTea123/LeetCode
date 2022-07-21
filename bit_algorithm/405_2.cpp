#include<bits/stdc++.h>
using namespace std;

/*
    另一种进行无符号右移的方法，将int类型转换为usigned int类型再直接右移即可
*/

class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        string res = "";
        unsigned int n = num;
        while(n != 0 ){
            int x = n & 15;   //拿到低4位
            n >>= 4;
            char ch = (x < 10)? x+'0':x-10+'a';
            res = ch + res;
        }
        return res;
    }
};