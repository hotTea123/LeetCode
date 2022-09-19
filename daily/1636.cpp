#include <bits/stdc++.h>
using namespace std;

// 2022.9.19 每日一题
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> cnt(201, 0);
        for(auto num:nums)
            ++cnt[num+100];
        vector<pair<int, int>> arr;
        for(int i=0;i < 201;i++){
            if(!cnt[i])
                continue;
            arr.emplace_back(make_pair(i-100, cnt[i]));
        }
        sort(arr.begin(), arr.end(), [](auto x, auto y){
            if(x.second == y.second)
                return x.first > y.first;
            return x.second < y.second;
        });
        vector<int> res(nums.size());
        int i=0;
        for(auto n:arr){
            for(int k=0;k < n.second;k++){
                res[i] = n.first;
                ++i;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,1,2,2,2,3};
    vector<int> res = Solution().frequencySort(nums);
    return 0;
}