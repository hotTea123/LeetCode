#include<bits/stdc++.h>
using namespace std;

/*
    cnt存放每个元素出现的次数，multiset维护前k大的出现次数，再遍历cnt判断出现次数有没有在set里
    时间复杂度O(nlogk)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int num:nums)
            ++cnt[num];
        multiset<int, greater<int>> topK;
        for(auto n:cnt){
            topK.insert(n.second);
            if(topK.size() > k)
                topK.erase(*topK.rbegin());
        }
        vector<int> res(k);
        int s = 0;
        for(auto n:cnt){
            if(topK.find(n.second) != topK.end()){
                res[s] = n.first;
                ++s;
            }
        }
        return res;
    }
};