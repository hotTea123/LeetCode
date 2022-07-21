#include<bits/stdc++.h>
using namespace std;

/*
    把二进制的4位转化为十六进制的一位，关键在于右移4位后前面会填充符号位，也就是说对于负数来说，前面会全部填充
  0，这样就会导致num永远不等于0，java中有>>>表示无符号右移，可是c++没有，只能手动把前4位置为0，可以采取先把
  1111 左移28变成 1111 0000 0000... 然后再取反变成 0000 1111 1111...，然后跟num做且运算就可
    将int转换为char可采用 x+'0'的做法，char转为int同理 x-'0'
*/
class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        string res = "";
        while(num != 0 ){
            int x = num & 15;   //拿到低4位
            num = num >> 4;
            //把前4位置为0
            num &= ~(15 << 28);
            char ch = (x < 10)? x+'0':x+'W';
            res = ch + res;
        }
        return res;
    }
};