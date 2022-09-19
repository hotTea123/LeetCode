#include <bits/stdc++.h>
using namespace std;

// 2022.9.14 每日一题
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size() / 20;
        double sum = 0;    //这里必须把sum置为double类型
        for(int i=sz;i < arr.size()-sz;i++)
            sum += arr[i];
        double res = sum / (arr.size()-2*sz);
        return res;
    }
};

// 或者这样 只要有一个是double类型就可以
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size() / 20;
        int sum = 0;
        for(int i=sz;i < arr.size()-sz;i++)
            sum += arr[i];
        double res = sum / (arr.size()*0.9);
        return res;
    }
};