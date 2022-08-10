#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int computePower(long long A, int m){
    //快速幂求A的m次方
    long long ret = 1;
    while(m > 1){
        if(m % 2==0){
            A = A * A % MOD;
            m /= 2;
        }else{
            ret = ret * A % MOD;
            --m;
        }
    }
    ret = ret * A % MOD;
    return ret;
}

//从n个中拿m个
int computeC1(int n, int m, vector<int>& factorial){
    long long ret = 1;
    for(int i=1;i <= n;i++){
        ret = ret * i % MOD;
        factorial[i] = ret;
    }
    //求乘法逆元
    ret = ret * computePower(factorial[m], MOD-2) % MOD;
    ret = ret * computePower(factorial[n-m], MOD-2) % MOD;
    return ret;
}


int computeC2(int n, int m, vector<vector<int>>& c){
    if(n-m < m)
        m = n - m;
    if(c[n][m] != 0)
        return c[n][m];
    if(m == 1){
        c[n][m] = n;
    }else{
        long long ret = computeC2(n-1, m-1, c)+computeC2(n-1, m, c);
        c[n][m] = ret % MOD;
    }
    return c[n][m];
}