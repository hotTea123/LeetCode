#include<bits/stdc++.h>
using namespace std;

//核心在于确保第i个数之前的数全都出现过了，则可以形成一个块
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxNum = 0, res = 0;
        for(int i=0;i < arr.size();i++){
            maxNum = max(maxNum, arr[i]);
            if(i == maxNum)
                ++res;
        }
        return res;
    }
};