#include<bits/stdc++.h>
using namespace std;

/*
    跟只出现一次的数字I一样，先对所有数做异或运算，得到的结果是那两个不同的数的异或，拿出他们任意不相同的一位，
  即异或后结果为1的某一位(这里取最右边的一位)，然后根据这一位的不同将所有数分为两组，这样那两个不同的数一定被
  划分到不同的组了，再对每组取异或和，最终的结果就是那两个数。
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        long sum = 0;
        for(int num:nums)
            sum ^= num;
        int x = sum & (-sum);

        for(int num:nums){
            if( (num & x) == 0)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};