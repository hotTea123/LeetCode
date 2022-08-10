#include<bits/stdc++.h>
using namespace std;

/*
    第13行中，ret一定是能除尽的，因为j从1开始，i和j同步++，因此i加了j次这其中一定有j的倍数
*/
class Solution {
private:
    int computeC(int n, int m){
        m = max(m, n-m);
        long long ret = 1;
        for(int i=m+1, j=1;j <= n-m;i++,j++)
            ret = ret*i / j;
        return ret;
    }
public:
    int uniquePaths(int m, int n) {
        //求组合数C(n-1,m+n-2)
        return computeC(m+n-2, n-1);
    }
};