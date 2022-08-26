#include<bits/stdc++.h>
using namespace std;

// 数组比unordered_map快好多，之后能用静态数组就用
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt(1001);
        for(auto num:target)
            ++cnt[num];
        for(auto num:arr)
            --cnt[num];
        for(int i=0;i < 1001;i++){
            if(cnt[i] != 0)
                return false;
        }
        return true;
    }
};