#include<bits/stdc++.h>
using namespace std;

//在1的基础上运用一个unordered_map进行查询优化，使时间复杂度提升到了O(n²)
//添加了一个dp优化：剪枝
//可行性剪枝：j从i遍历至0，如果arr[i]-arr[j] > arr[j]，那么肯定不存在符合条件的数了（因为是递增的）
//最优性剪枝：当前最大长度是res，只有当以arr[j]为倒数第二个数时的理论最大长度j+2>res时，才有继续往下搜索的必要


class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int arrlen=arr.size(), res=0;
        vector<vector<int>> dp(arrlen, vector<int>(arrlen, 0));
        unordered_map<int, int> arrMap;
        for(int i=0;i < arrlen;i++){
            arrMap[arr[i]] = i;
        }
        for(int i=1;i < arrlen;i++){
            for(int j=i-1;j>=0 && arr[i] - arr[j] < arr[j];j--){
                int dif = arr[i] - arr[j];
                if(arrMap.find(dif) != arrMap.end()){
                    dp[j][i] = max(dp[arrMap[dif]][j]+1, 3);
                    res = max(dp[j][i], res);
                }
            }
        }
        return res;
    }
};
