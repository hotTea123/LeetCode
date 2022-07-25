#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        if(day == 1)
            return 0;
        int dp = 0;
        int minPrice = prices[0], maxPrice = 0;
        for(int i = 1;i < day;i++){
            dp = max(dp, prices[i]-minPrice);
            if(prices[i] < minPrice)
                minPrice = prices[i];
            if(dp > maxPrice)
                maxPrice = dp;
        }
        return maxPrice;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int res = Solution().maxProfit(prices);
    return 0;
}