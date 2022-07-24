#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
private:
    //求一个数的质因数分解情况
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
    int computeC(int n, int m, vector<int>& factorial){
        long long ret = factorial[n];
        //求乘法逆元
        ret = ret * computePower(factorial[m], MOD-2) % MOD;
        ret = ret * computePower(factorial[n-m], MOD-2) % MOD;
        return ret;
    }
    

public:
    int idealArrays(int n, int maxValue) {
        vector<vector<int>> c(n+13, vector<int>(14, 0));
        vector<int> factorial(n+13);
        long long ret = 1;
        for(int i=1;i < factorial.size();i++){
            ret = ret * i % MOD;
            factorial[i] = ret;
        }

        int res = 1;   //以1结尾
        for(int i=2;i <= maxValue;i++){
            vector<int> factor = computeFactors(i);
            long long cSum = 1;
            for(int j=0;j < factor.size();j++){
                int k = factor[j]+n-1, m = min(factor[j], n-1);
                if(c[k][m] == 0)
                    c[k][m] = computeC(k, m, factorial);
                cSum = cSum * c[k][m] % MOD;
            }
            res = (res + cSum) % MOD;
        }
        return res;
    }
};

int main(){
    int n = 2, maxValue = 5;
    int res = Solution().idealArrays(n, maxValue);
    return 0;
}