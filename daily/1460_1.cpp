#include<bits/stdc++.h>
using namespace std;

 // 2022.8.24 每日一题
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> cnt;
        for(auto num:target)
            ++cnt[num];
        for(auto num:arr){
            --cnt[num];
            if(cnt[num] == 0)
                cnt.erase(num);
        }
        if(cnt.empty())
            return true;
        return false;
    }
};