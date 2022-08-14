#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> sum(n, 0);
        int res = 0;
        long long maxSum = 0;
        for(int i=0;i < n;i++){
            sum[edges[i]] += i;
            if(maxSum < sum[edges[i]]){
                maxSum = sum[edges[i]];
                res = edges[i];
            }else if(maxSum == sum[edges[i]])
                res = min(res, edges[i]);
        }
        return res;
    }
};