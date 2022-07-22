#include<bits/stdc++.h>
using namespace std;

//操作技巧：怎么把第i位置0： num &= ~(1 << i)
class Solution {
public:
    int findComplement(int num) {
        //该题关键在于如何求出最左边为1的那一位
        num = ~num;
        for(int i=31;i >= 0;i--){
            if(num >> i & 1){
                num &= ~(1 << i);
            }else
                break;
        }
        return num;
    }
};

int main(){
    int res = Solution().findComplement(5);
    return 0;
}