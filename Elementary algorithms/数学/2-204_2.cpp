#include<bits/stdc++.h>
using namespace std;

/*
    欧式筛:与埃氏筛思想类似，但是还需要一个数组存放已经遍历过的素数，然后从2开始对每个数执行乘以数组中的
  素数的操作，注意：埃氏筛是将所有素数乘以以那个数开始的所有数所对应的数标为false
    其关键在于：如果某个数i mod prime[j] == 0的时候，就停止这一轮筛了(模等于0那次还要筛)
        (虽然还是不是很理解为什么)
        时间复杂度O(n),但是最后的执行速度却比法一慢，应该是因为使用动态数组的原因
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        vector<bool> isPrime(n, true);
        vector<int> fac;
        int res = n-2;
        for(int i=2;i < n;i++){
            if(isPrime[i])
                fac.emplace_back(i);
            else
                --res;
            for(int j=0;j < fac.size()&&i*fac[j]<n;j++){
                isPrime[i*fac[j]] = false;
                if(i % fac[j] == 0)
                    break;
            }
        }
        return res;
    }
};

int main(){
    int res = Solution().countPrimes(10);
    return 0;
}