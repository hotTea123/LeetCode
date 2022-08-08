#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> taskTime;
        int n = tasks.size();
        long long cur = 0;
        for(int i=0;i < n;i++){
            ++cur;
            if(taskTime.find(tasks[i]) != taskTime.end() && (cur - taskTime[tasks[i]]) <= space)
                cur += space - (cur - taskTime[tasks[i]]) + 1;
            taskTime[tasks[i]] = cur;
        }
        return cur;
    }
};

int main(){
    vector<int> tasks = {1,2,1,2,3,1};
    long long res = Solution().taskSchedulerII(tasks, 3);
    return 0;
}