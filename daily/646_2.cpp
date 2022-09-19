#include <bits/stdc++.h>
using namespace std;

/* 
    关键在于对res的定义, res[i]定义为长度为i+1的数对链结尾的最小值
    ---------重点方法------------
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> res;
        for(int i=0;i < pairs.size();i++){
            if(res.size() == 0 || pairs[i][0] > res.back())
                res.emplace_back(pairs[i][1]);
            else{
                auto idx = lower_bound(res.begin(), res.end(), pairs[i][0]);
                *idx = min(*idx, pairs[i][1]);
            }
        }
        return res.size();
    }
};
