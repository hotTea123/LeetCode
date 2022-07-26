#include<vector>
using namespace std;

//错误解
//[7,1,5,3,6,4]，贪心算法是错误的
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyTime = -1, i=1;
        if(prices.size() == 1)
            return 0;
        vector<int> profit;
        while(i < prices.size()){
            if(prices[i-1] < prices[i] && buyTime == -1)
                buyTime = i-1;
            else if(prices[i-1] > prices[i] && buyTime != -1){
                profit.emplace_back(prices[i-1]-prices[buyTime]);
                buyTime = -1;
            }
            ++i;
        }
        if(buyTime != -1)
            profit.emplace_back(prices[i-1]-prices[buyTime]);
        int maxProfit = 0;
        for(i=0;i<profit.size();i++){
            if(profit[i] > maxProfit)
                maxProfit = profit[i]; 
        }
        return maxProfit;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int res = Solution().maxProfit(prices);
    return 0;
}