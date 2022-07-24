#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int gcd(int a,int b){
        if(a < b)
            swap(a, b);
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int> numsCount;
        for(int i:nums)
            numsCount[i]++;

        //求出最大的公约数
        int fac = numsDivide[0];
        for(int i:numsDivide){
            fac = gcd(fac, i);
        }
        int res = 0;
        for(auto n:numsCount){
            if(fac % n.first == 0)
                return res;
            res += n.second;
        }
        return -1;
    }
};