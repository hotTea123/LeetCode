#include<bits/stdc++.h>
using namespace std;

// 2022.8.18每日一题
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;
        map<int, unordered_set<int>> cntSet;
        int res = 1;
        for(int i=0;i < nums.size();i++){
            ++cnt[nums[i]];
            if(cnt[nums[i]] > 1){
                cntSet[cnt[nums[i]]-1].erase(nums[i]);
                if(cntSet[cnt[nums[i]]-1].size() == 0)
                    cntSet.erase(cnt[nums[i]]-1);
            }
            cntSet[cnt[nums[i]]].insert(nums[i]);
            if(cntSet.size() == 1 && cntSet.begin()->first == 1){
                res = i+1;
            }else if(cntSet.size() == 2){
                auto it1=cntSet.begin();
                auto it2=cntSet.rbegin();
                int len1 = it1->second.size(), len2 = it2->second.size();
                if(len1 != 1 && len2 != 1)
                    continue;
                if(it1->first == 1 && (len1 == 1 || it2->first == 2))
                    res = i+1;
                else if(it1->first+1 == it2->first)
                    res = i+1;
            }
        }
        return res;
    }
};