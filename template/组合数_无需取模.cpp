#include<bits/stdc++.h>
using namespace std;

//求C(n, m)  n大
int computeC(int n, int m){
    m = max(m, n-m);
    long long ret = 1;
    for(int i=m+1, j=1;j <= n-m;i++,j++)
        ret = ret*i / j;
    return ret;
}