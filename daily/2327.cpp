#include<vector>
using namespace std;

#define MOD 1e9 + 7

class Solution {
private:
    int next(int pre, int n){
        if(pre == 0)
            return n;
        return pre-1;
    }

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
            vector<long long> delayDay(delay+1, 0), forgetDay(forget+1, 0);
            long long knowCount = 1, everyDayShare = 0;
            delayDay[0] = 1;
            forgetDay[0] = 1;
            int forgetStart=0, forgetEnd=forget;
            int delayStart=0, delayEnd=delay;
        for(int i=1;i <= n;i++){
            if(forgetDay[forgetEnd] != 0){
                //之前一直没有加这个，导致结果为负数
                while(everyDayShare < forgetDay[forgetEnd])
                    everyDayShare += MOD;
                everyDayShare -= forgetDay[forgetEnd]; 

                while(knowCount < forgetDay[forgetEnd])
                    knowCount += MOD;
                knowCount -= forgetDay[forgetEnd];                
                forgetDay[forgetEnd] = 0;
            }
            
            
            knowCount += everyDayShare;
            delayDay[delayStart] += everyDayShare;
            forgetDay[forgetStart] += everyDayShare;

            knowCount %= int(MOD);
            everyDayShare %= int(MOD);    
            forgetDay[forgetStart] %= int(MOD);
            delayDay[delayStart] %= int(MOD);
            

            if(delayDay[delayEnd] != 0){
                everyDayShare += delayDay[delayEnd];
                knowCount += delayDay[delayEnd];
                delayDay[delayStart] += delayDay[delayEnd];
                forgetDay[forgetStart] += delayDay[delayEnd];
                delayDay[delayEnd] = 0;
            }
            knowCount %= int(MOD);
            everyDayShare %= int(MOD);    
            forgetDay[forgetStart] %= int(MOD);
            delayDay[delayStart] %= int(MOD);

            delayStart = next(delayStart, delay);
            delayEnd = next(delayEnd, delay);
            forgetStart = next(forgetStart, forget);
            forgetEnd = next(forgetEnd, forget);
        }
        return knowCount;
    }
};


int main(){
    int n = 904, delay = 63, forget = 102;
    int res = Solution().peopleAwareOfSecret(n, delay, forget);
    return 0;
}