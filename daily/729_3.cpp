#include<map>
using namespace std;

//731中的方法4
class MyCalendar {
private:
    map<int, int> calendar;

public:
    MyCalendar() {
        calendar[0] = 0;
        calendar[INT_MAX] = 0;
    }
    
    bool book(int start, int end) {
        auto iter = calendar.lower_bound(start);
        if(iter->first != start)
            --iter;
        auto it = iter;
        while(it->first < end){
            if(it->second == 1)
                return false;
            ++it;
        }
        while(iter->first < end){
            if(iter->first != start){
                calendar[start]++;
                ++iter;
            }else
                iter->second++;
            ++iter;
        }
        if(iter->first != end)
            calendar[end] = 0;
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */