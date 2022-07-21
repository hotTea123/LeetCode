#include<bits/stdc++.h>
using namespace std;

/*
    位运算：将每个数的每一位(int有32位)存入一个32大小的数组中，记录每一位的和值，然后将每一位的结果mod 3，
  最后数组中各位的结果转化为二进制就是那个单独的数
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32,0);
        for(int num:nums){
            for(int i=0;i < 32;i++){
                if(num >> i & 1 == 1)
                    cnt[i]++;
            }
        }

        int res = 0;
        for(int i=0;i < 32;i++){
            if( cnt[i] % 3 == 1)
                res |= 1 << i;
        }
        return res;
    }
};