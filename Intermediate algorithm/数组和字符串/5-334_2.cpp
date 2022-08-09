#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = INT_MAX-1, mid = INT_MAX;
        for(int num:nums){
            if(num <= low){
                low = num;
            }else if(num <= mid){
                mid = num;
            }else
                return true;
        }
        return false;
    }
};