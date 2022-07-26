#include<bits/stdc++.h>
using namespace std;

/*
    单调栈题目的思路：一般都是将给的所有元素入一遍单调栈，只需要观察各元素入栈出栈时栈中弹出元素的信息或者栈中
  剩余元素的信息跟答案的对应关系
*/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i] > st.top()){
                st.pop();
                res[i]++;
            }
            if(!st.empty())
                ++res[i];
            st.push(heights[i]);
        }
        return res;
    }
};