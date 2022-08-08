#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> weight;
        for(int i=0;i < items1.size();i++)
            weight[items1[i][0]] += items1[i][1];
        for(int i=0;i < items2.size();i++)
            weight[items2[i][0]] += items2[i][1];
        vector<vector<int>> res(weight.size(), vector<int>(2));
        int i=0;
        for(auto n:weight){
            res[i][0] = n.first;
            res[i][1] = n.second;
            ++i;
        }
        return res;
    }
};