#include<bits/stdc++.h>
using namespace std;

/*
    每次存储直接放入一个pair，存放数字和放入那个数字时的最小值
    这样每次操作时间复杂度都是O(1)
*/
class MinStack {
private:
    vector<pair<int, int>> arr;   //第一个存放当前值，第二个存放最小值
public:
    MinStack() {}
    
    void push(int val) {
        auto x = make_pair(val, val);
        if(arr.size())
            x.second = min(arr.back().second, val);
        arr.emplace_back(x);
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */