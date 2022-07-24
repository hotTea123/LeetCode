#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = 0, dis = 0;
        int i = start;
        int res;
        while(n < distance.size()){
            if(i == destination){
                res = dis;
                dis = 0;
            }
            dis += distance[i];
            i = (i+1)%distance.size();
            ++n;
        }
        return min(dis, res);
    }
};