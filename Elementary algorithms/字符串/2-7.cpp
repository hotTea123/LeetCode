#include<bits/stdc++.h>
using namespace std;

//关键在于，如何判断反转后的数值是否越界
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool op = x>0 ? true:false;
        while(x != 0){
            if(op && res > (INT_MAX-x%10)/10)
                return 0;
            if(!op && res < (INT_MIN-x%10)/10)
                return 0;
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
};