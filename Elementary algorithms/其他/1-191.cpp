#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n > 0){
            n &= ~(n&-n);
            ++res;
        }
        return res;
    }
};