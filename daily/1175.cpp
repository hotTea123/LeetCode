#include<cmath>
#include<algorithm>
using namespace std;


//数学题
//对于全乘法来说，在任意时候取模跟在最后取模的结果是一样的
class Solution {
private:
    const int m = int(1e+9) + 7;
public:
    int numPrimeArrangements(int n) {
        int unprime = 1;
        int prime = 0;
        if(n >= 2)
            ++prime;
        else
            return 1;
        for(int i=3;i <= n;i++){
            int j;
            for(j = 2;j <= sqrt(i);j++){
                if(i % j == 0)
                    break;
            }
            if(j > sqrt(i))
                ++prime;
        }
        unprime = n - prime;
        int maxNum = max(unprime, prime);
        int minNum = min(unprime, prime);
        unsigned long res = 1;
        for(int i = minNum;i>1;i--){
            res *= i*i;
            res %= m;
        }

        for(int i=maxNum;i > minNum;i--){
            res *= i;
            res %= m;
        }
        return res;
    }
};

int main(){
    int n = 17;
    int res = Solution().numPrimeArrangements(n);
    return 0;
}