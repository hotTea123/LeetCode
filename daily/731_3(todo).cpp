#include<bits/stdc++.h>
using namespace std;

//线段树法  todo
class MyCalendarTwo {
private:
    map<int, int> diff;

public:
    MyCalendarTwo() {
        
    }

    bool book(int start, int end) {
    }
};

int main(){
    MyCalendarTwo can;
    vector<vector<int>> input = {{47,50},{1,10},{27,36},{40,47},{20,27},{15,23},{10,18},{27,36},{17,25},{8,17},{24,33},{23,28},{21,27},{47,50},{14,21},{26,32},{16,21},{2,7},{24,33},{6,13},{44,50},{33,39},{30,36},{6,15},{21,27},{49,50},{38,45},{4,12},{46,50},{13,21}};
    for(auto n:input)
        can.book(n[0], n[1]);
    return 0;
}


