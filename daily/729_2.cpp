#include<bits/stdc++.h>
using namespace std;

//差分法
class MyCalendar {
private:
    map<int, int> diff;

public:
    bool book(int start, int end) {
        ++diff[start], --diff[end];
        int sum = 0;
        for(auto& [a,b]:diff){
            sum += b;
            if(sum > 1){
                --diff[start], ++diff[end];
                return false;
            }
            if(a > end)
                break;
        }
        return true;
    }
};