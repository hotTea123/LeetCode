#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cnt;
        for(auto c:s)
            cnt[c]++;

        for(auto c:t)
            cnt[c]--;
        
        int diff = 0;
        for(auto c:cnt)
            diff += abs(c.second);
        
        if(diff)
            return false;
        return true;
    }
};