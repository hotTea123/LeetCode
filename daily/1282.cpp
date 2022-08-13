#include<bits/stdc++.h>
using namespace std;

// 2022.8.12每日一题
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        vector<vector<int>> res;
        for(int i=0;i < groupSizes.size();i++){
            hash[groupSizes[i]].emplace_back(i);
            if(hash[groupSizes[i]].size() == groupSizes[i]){
                res.emplace_back(hash[groupSizes[i]]);
                hash[groupSizes[i]].clear();
            }
        }
        return res;
    }
};