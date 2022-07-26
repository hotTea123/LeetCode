#include<bits/stdc++.h>
using namespace std;

/*
    1.简单模拟
    2.使用一些位运算的技巧
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long a = n >> 1;
        a = a ^ n;
        //如何判断一个数二进制是否全为1
        return (a & (a + 1)) == 0;
    }
};

int main(){
    int res = Solution().hasAlternatingBits(7);
}