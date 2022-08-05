#include<bits/stdc++.h>
using namespace std;

/*
    将每个字符串排序，并将排序后的string作为map的key，将原字符串加到key对应的value的数组中
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        string key;
        for(int i=0;i < strs.size();i++){
            key = strs[i];
            sort(key.begin(), key.end());
            hash[key].emplace_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto &n:hash){
            res.emplace_back(n.second);
        }
        return res;
    }
};