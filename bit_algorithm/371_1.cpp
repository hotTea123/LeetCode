#include<bits/stdc++.h>
using namespace std;

/*
    朴素的思路，用一位标志是否进位
*/

class Solution {
public:
    int getSum(int a, int b) {
        bool flag = false;   //进位标志
        int res = 0;
        for(int i=0;i < 32;i++){
            bool x = a >> i & 1, y = b >> i & 1;
            if(x & y & flag){
                //1 1 1
                res |= 1 << i;
            }else if(!(x | y | flag)){
                //0 0 0
                continue;
            }
            else if(x ^ y ^ flag){
                // 0 0 1
                res |= 1 << i;
                flag = false;
            }else{
                // 0 1 1
                flag = true;
            }
                
        }
        return res; 
    }
};