#include<bits/stdc++.h>
using namespace std;

/*
    要进行的操作：区间插入、区间更新，方法多样，选择数据结构很关键！！但是不好想
    1.第一种方法是线段树，提到区间上的操作很容易想到线段树，但是由于数据是1e9，因此需要动态开点(待学习)
    2.第二种方法是直接暴力，维护两个数组，一个表示该段时间已经预定(第一次book)，然后在该数组基础上用
  (start,end)求跟每个时间段重叠的部分，存放到第二个数组overlap(第二次book)，判断时只需要判断start和end
  跟overlap数组是否有重叠部分。
    3.第三种方法使用差分数组进行区间更新,考虑到数组很大，因此采用map，主要思想就是在start处让map加1，在
  end处让map减一，因此你可以求得任意位置预定的次数(只需要把前面所有的加起来)
    4.第四种方法，也就是下面的代码思想：map的第一个表示开始时间，map的第二个表示次数(可取0,1,2)，初始化
  时插入[0]和[INT_MAX]使得在做lower_bound时不用考虑边界条件，所有的start/end都会被放到map中
*/
class MyCalendarTwo {
private:
    map<int, int> calendar;

public:
    MyCalendarTwo() {
        calendar[0] = 0;
        calendar[INT_MAX] = 0;
    }

    bool book(int start, int end) {
        auto iter = calendar.lower_bound(start);
        if(iter->first != start)
            --iter;
        auto it = iter;
        while(it->first < end){
            if(it->second == 2)
                return false;
            ++it;
        }
        //插入
        bool startFlag = true;
        while(iter->first < end){
            if(startFlag && start != iter->first){
                calendar[start] = iter->second+1;
                iter++;
            }else{
                iter->second++;
            }
            ++iter;
            startFlag = false;
        }
        if(iter->first != end){
            --iter;
            calendar[end] = iter->second-1;
        }
        return true;
    }
};

int main(){
    MyCalendarTwo can;
    vector<vector<int>> input = {{47,50},{1,10},{27,36},{40,47},{20,27},{15,23},{10,18},{27,36},{17,25},{8,17},{24,33},{23,28},{21,27},{47,50},{14,21},{26,32},{16,21},{2,7},{24,33},{6,13},{44,50},{33,39},{30,36},{6,15},{21,27},{49,50},{38,45},{4,12},{46,50},{13,21}};
    for(auto n:input)
        can.book(n[0], n[1]);
    return 0;
}


