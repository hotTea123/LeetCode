#include<bits/stdc++.h>
using namespace std;

/* 思想方法：模拟一遍找到最后一个能上车的人，在他之前上车即可
 * 想不到想不到想不到，知道答案后又觉得不难，就很奇怪。
    中间有一坨的处理很容易出错，建议隔段时间重写这题
 * 乘客的长度为n，时间复杂度O(n)
 */
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int m = buses.size(), n = passengers.size();
        int j = 0;  //指向乘客的指针
        //上车
        int rest = capacity;
        for(int i=0;i <m;i++){
            rest = capacity;
            while(rest > 0 && j < n && buses[i] >= passengers[j]){
                --rest;
                ++j;
            }
        }
        //最后一个上车的乘客是j-1
        //这一坨的处理一直出错
        int res;
        res = (rest > 0) ? buses[m-1] : passengers[j-1];
        while(j > 0 && res == passengers[j-1]){
            --res;
            --j;
        }
        return res;
    }
};

int main(){
    vector<int> buses = {3}, passengers = {2,3};
    int capacity = 3;
    int res = Solution().latestTimeCatchTheBus(buses, passengers, capacity);
    return 0;
}

