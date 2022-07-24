#include<bits/stdc++.h>
using namespace std;

/*  数学法
    思想：分两种情况，设最大为z，其余两个为x,y。
    1.如果z>=x+y，则可以让最大的数和另外两个一一匹配，直接返回z。
    2.如果z<x+y，则先将最大的数和其他的一一匹配，剩余x+y-z，可以将这一部分平分成两份（两两配对），即
    (x+y-z)/2向上取整，最后答案就是两部分的和。
*/
class Solution {
public:
    int fillCups(vector<int>& amount) {
        //数学法：失败
        int flag = 0;
        sort(amount.begin(), amount.end());
        if(amount[0] + amount[1] <= amount[2])
            return amount[2];
        return (amount[0]+amount[1]-amount[2]+1)/2 + amount[2];
    }
};