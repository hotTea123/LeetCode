#include<bits/stdc++.h>
using namespace std;

// 使用STL封装的堆priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto num:nums)
            q.push(num);
        while(k > 1){
            --k;
            q.pop();
        }
        return q.top();
    }
};