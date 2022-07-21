#include<map>
#include<set>
#include<vector>
using namespace std;

//第一次使用set这种数据结构，还不熟悉
//set有lower_bound和upper_bound两个函数，默认是取大于等于/大于val的第一个数
//若想拿到小于等于/小的第一个数于可是使用lower_bound(val, greater<int>)
//这是最朴素的实现，当我写了我的日程表II后又更新了两种更高级的做法(729_2/729_3)
class MyCalendar {
private:
    map<int, int> canlendar;
    set<int> startTime;

public:
    bool book(int start, int end) {
        bool flag = false;
        if(canlendar.size() == 0){
            flag = true;
        }else{
            auto it = startTime.upper_bound(start);
            if(it == startTime.begin() && end <= *it){
                flag = true;
            }else if(end <= *it || it == startTime.end()){
                it--;
                if(start >= canlendar[*it])
                    flag = true;
            }
        }
             
        if(flag){
            canlendar[start] = end;
            startTime.insert(start);
            return true;
        }
        return false;
    }
};


int main(){
    MyCalendar my;
    bool a;
    vector<vector<int>> canlender = {{37,50},{33,50},{4,17},{35,48},{1,2}};
    for(int i=0;i < canlender.size();i++)
        a = my.book(canlender[i][0], canlender[i][1]);
    return 0;
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */