#include<bits/stdc++.h>
using namespace std;

/*
    埃氏筛:这是一种筛素数的思想，需要一个额外的bool数组存储每个数是否是素数(全标为true(是素数))，然后
  从2开始将所有n以内的能被2整除的数标为false,然后从下一个还是素数的数(也就是数组中为true)继续执行此操作
    优化点：不需要每个数x都按照2x、3x、4x这样筛，因为2x已经被2筛过了，3x已经被3筛过了，而4x也被2筛过了，
  所以每次应从x*x开始筛
        时间复杂度O(nloglogn)
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        vector<bool> isPrime(n, true);
        int res = n-2;   //减去0、1
        for(int i=2;i < n;i++){
            if(!isPrime[i])
                continue;
            for(int j=i;(long)i*j<n;j++){
                if(isPrime[i*j]){
                    isPrime[i*j] = false;
                    --res;
                }
            }
        }
        return res;
    }
};