#include<bits/stdc++.h>
using namespace std;

/*
    数学法，从起点到终点，一共需要走n+m-2次，其中向下走m-1次，向右走n-1次，因此只需要看做将m-1个物品放
  至m+n-2个盒子里，即C(m+n-2, n-1)
    以下是我自己写的无需取模的组合数求法，但是还能改进，见2-62_3
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        //求组合数C(n-1,m+n-2)
        long long res = 1;
        int j = min(m-1, n-1);
        for(int i=m+n-2;i > max(m-1, n-1);i--){
            res *= i;
            while(j > 1 && res % j == 0){
                res /= j;
                --j;
            }
        }
        while(j >1)
            res /= j;
        return res;
    }
};