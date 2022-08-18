#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxcnt = 0, maxfreq = 0;
        vector<int> taskCnt(26, 0);
        for(auto task:tasks){
            ++taskCnt[task-'A'];
            if(maxcnt == taskCnt[task-'A'])
                ++maxfreq;
            else if(maxcnt < taskCnt[task-'A']){
                maxcnt = taskCnt[task-'A'];
                maxfreq = 1;
            }
        }
        return max((int)tasks.size(), (maxcnt-1)*(n+1)+maxfreq);
    }
};