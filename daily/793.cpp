#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int preimageSizeFZF(int k) {
        int i= 0;
        vector<int> div;
        int d = 1, sum = 0;
        while(k > sum){
            d *= 5;
            div.emplace_back(d);
            sum += d;
        }
        //将div.back()和5*div.back()二分
    }
};