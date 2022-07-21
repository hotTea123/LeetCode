#include<bits/stdc++.h>
using namespace std;

/*
    思路：异或是没有进位的加法，而只有当两个数的某一位都为1时才需要进位，两个数且运算的结果左移一位则是进位后的
  结果，那么现在只需要将异或后的数和进位结果相加，也就是再调用getSum函数，直到进位结果为0也就是不需要再进位为止

    还有一个细节：在 C++ 的实现中，当我们赋给带符号类型一个超出它表示范围的值时，结果是undefined；而当我们赋给
  无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模的余数。因此，我们可以使用无符号类
  型来防止溢出。

*/

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0)
            return a;
        unsigned int add = (unsigned int)(a & b) << 1;
        a = a ^ b;
        return getSum(a, add);
    }
};


int main(){
    int res = Solution().getSum(-324,-34);
    return 0;
}