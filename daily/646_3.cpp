#include <bits/stdc++.h>
using namespace std;

/* 
    贪心做法：每次拿取最大的p[1]，及其对应的最大的p[0]，然后记录下拿取到的p[0]
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto x, auto y){
            if(x[1] == y[1])
                return x[0] > y[0];
            return x[1] > y[1];
        });
        int pre = INT_MAX, res = 0;
        for(int i=0;i < pairs.size();i++){
            if(pairs[i][1] < pre){
                ++res;
                pre = pairs[i][0];
            }
            pre = max(pre, pairs[i][0]);   //这一句很关键，主要是保证拿到的pre是当前最大的
        }
        return res;
    }
};
int main(){
    vector<vector<int>> pairs = {{9,10},{9,10},{4,5},{-9,-3},{-9,1},{0,3},{6,10},{-5,-4},{-7,-6}};
    int res = Solution().findLongestChain(pairs);
    return 0;
}