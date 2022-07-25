#include<vector>
using namespace std;

//时间复杂度O(n)，空间复杂度O(1)，贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buyTime = -1;
        int i;
        for(i=0;i < prices.size()-1;i++){
            if(prices[i] < prices[i+1] && buyTime == -1){
                buyTime = i;
            }else if(prices[i+1] < prices[i] && buyTime != -1){
                profit += prices[i] - prices[buyTime];
                buyTime = -1;
            }
        }
        if(buyTime != -1)
            profit += prices[i] - prices[buyTime];
        return profit;
    }
};

int main(){
    //vector<int> prices = {1,7,1,5,3,6,4};
    //vector<int> prices = {1,2,3,4,5};
    vector<int> prices = {7,1,5,3,6};
    int res = Solution().maxProfit(prices);
    return 0;
}