#include <bits/stdc++.h>
using namespace std;

// 2022.8.31每日一题
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0, j =0;
        while(i < pushed.size() && j < popped.size()){
            if(!st.empty() && st.top() == popped[j]){
                ++j;
                st.pop();
            }else{
                st.push(pushed[i]);
                ++i;
            }
        }
        while(j < popped.size() && st.top() == popped[j]){
            st.pop();
            ++j;
        }
        if(st.empty())
            return true;
        return false;
    }
};