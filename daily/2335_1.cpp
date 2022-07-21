#include<bits/stdc++.h>
using namespace std;

//用数学法尝试了好多次都失败了...数学太差了，分类讨论没讨论好，然后看到数据量很小直接模拟一遍过...
//时间复杂度O(n)
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int count = 0;
        if(amount[2] == 0)
            return 0;
        while(1){
            --amount[1];
            --amount[2];
            ++count;
            sort(amount.begin(), amount.end());
            if(amount[2] == 0)
                break;
        }
        return count;
    }
};