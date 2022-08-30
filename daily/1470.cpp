#include<bits/stdc++.h>
using namespace std;

//2022.8.29 每日一题
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2*n);
        int i=0, j=n;
        int k =0;
        while(i<n){
            res[k]=nums[i];
            ++i;
            ++k;
            res[k]=nums[j];
            ++j;
            ++k;
        }
        return res;
    }
};