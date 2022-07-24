#include<bits/stdc++.h>
using namespace std;

// c++ 自带加法函数
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(destination < start)
            swap(destination, start);
        int dis1 = accumulate(distance.begin()+start, distance.begin()+destination, 0);
        int dis2 = accumulate(distance.begin()+destination, distance.end(), 0);
        dis2 = accumulate(distance.begin(), distance.begin()+start, dis2);
        return min(dis1, dis2);
    }
};