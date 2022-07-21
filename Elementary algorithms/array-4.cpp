#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for(int num:nums){
            if(n.find(num) != n.end())
                return true;
            n.insert(num);
        }
        return false;
    }
};