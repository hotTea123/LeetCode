#include<bits/stdc++.h>
using namespace std;

/*
    思想仍然太过局限，想着存下一个全局的min，然后每次pop之后查找出新的全局最小值
    这样每次push、pop的时间复杂度都是O(logn)
*/
class MinStack {
private:
    map<int, int> cnt;
    vector<int> arr;
    int minVal;
public:
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        arr.emplace_back(val);
        ++cnt[val];
        minVal = min(minVal, val);
    }
    
    void pop() {
        int num = arr[arr.size()-1];
        arr.pop_back();
        if(!arr.size()){
            cnt.clear();
            minVal = INT_MAX;
            return;
        }
        --cnt[num];
        if(cnt[num] == 0){
            cnt.erase(num);
            if(minVal == num)
                minVal = cnt.begin()->first; 
        }
    }
    
    int top() {
        return arr[arr.size()-1];
    }
    
    int getMin() {
        return minVal;
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

