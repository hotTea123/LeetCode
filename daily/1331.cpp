#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> nums;
        for(int i:arr)
            nums.insert(i);
        unordered_map<int, int> sorted;
        int k=1;
        for(auto i:nums){
            sorted[i] = k;
            ++k;
        }
        vector<int> res(arr.size());
        for(int i=0;i<arr.size();i++){
            res[i] = sorted[arr[i]];
        }
        return res;
    }
};