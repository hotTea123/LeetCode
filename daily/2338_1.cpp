#include<bits/stdc++.h>
using namespace std;

/*
    思想方法：1.考虑以i(1<= i <= maxValue)结尾的数有多少个理想数组
             2.以i结尾的理想数组可以看成由1开始乘，最后经过一系列乘法得到i
                比如：1×3×4=12，而4又可以拆分，最终：1×2×2×3=12
    故i最终可以被拆成多个质数相乘，可以求出i的所有分解质因子
    现在有n个位置(理想数组长度为n)，把这些质因子放入n个位置的不同方案数则是以i结尾的长度为n的理想数组个数
    质因子中，有相同的，有不同的，分成两部分计算：
        ①相同：可以用组合数学中的将m个小球放入n个盒子，允许有空盒来模拟
         允许有空盒，那么先将每个盒子中放一个球，总共的球数变成了m+n个，再采用隔板法，用n-1块板
        去将m+n个求分成n份，共有m+n-1个位置可以隔，因此答案为C(m+n-1,n-1)
        ②不同：不同之间的质因数的放入方法可以用乘法原理相乘
    最后就可求出以i结尾的理想数组，求出[1, maxValue]所有的结果相加即为答案了。
    下面的问题就变成了求组合数：
        关于组合数有两个公式,对于我们求组合数有帮助：
            C(n, m) = C(n, n-m),所以求的时候取min(m, n-m)，可以减少运算量
            C(n, m) = C(n-1, m-1) + C(n-1, m)， 可以通过递推关系求组合数
        证明：考虑从n里面拿一个，如果拿到的属于m，则还有C(n-1,m-1),如果拿到的不属于m，则还有C(n-1,m)
    组合数的两种求法：
        ①记忆化递推：利用上述的第二个公式递推的求解组合数，同时将已经求出的结果保存在一个二维数组中
        ②乘法逆元+快速幂：直接使用原始公式C(n, m) = n!/m!(n-m)!,模运算对乘法和加法封闭但对除法不封闭，
        当除数很大的时候怎么办？可以通过乘法逆元解决，在模运算下，(A/B)%M = A * B^(M-2) % M(这结论真的
        好用)，其中，M需为质数。
      两种组合数求解方法使用条件不同，如果要求出C(n, m)以内的所有组合数显然用第一种方法，如果只求一个
      那么第二种更适用。
*/

const int MOD = 1e9 + 7;
class Solution {
    vector<int> computeFactors(int n){
        vector<int> factor;
        int i = 2, a = n;
        while(n > 1){
            //判断n能否被i除尽
            if(n % i != 0){
                ++i;
                continue;
            }
            //判断i是否是质数
            int j = 2;
            while(j <= sqrt(i)){
                if(i % j == 0)
                    break;
                ++j;
            }
            if(j > sqrt(i)){
                //i是质数
                int ret = 0;
                while(n % i == 0){
                    n /= i;
                    ++ret;
                }
                factor.emplace_back(ret);
            }
        }
        return factor;
    }

    int computeC(int n, int m, vector<vector<int>>& c){
        if(n-m < m)
            m = n - m;
        if(c[n][m] != 0)
            return c[n][m];
        if(m == 1){
            c[n][m] = n;
        }else{
            long long ret = computeC(n-1, m-1, c)+computeC(n-1, m, c);
            c[n][m] = ret % MOD;
        }
        return c[n][m];
    }

public:
    int idealArrays(int n, int maxValue) {
        int m = min(maxValue, n+13-maxValue);
        vector<vector<int>> c(n+13, vector<int>(14, 0));
        int res = 1;   //以1结尾
        for(int i=2;i <= maxValue;i++){
            vector<int> factor = computeFactors(i);
            long long cSum = 1;
            for(int j=0;j < factor.size();j++){
                cSum *= computeC(factor[j]+n-1, n-1, c);
                cSum %= MOD;
            }
            res = (res + cSum) % MOD;
        }
        return res;
    }
};

int main(){
    int n = 6, maxValue = 8;
    int res = Solution().idealArrays(n, maxValue);
    return 0;
}