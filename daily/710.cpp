#include<bits/stdc++.h>
using namespace std;

/* **********
 * 算法思想：将[0, n-m)中黑名单的数映射到[n-m, n]中白名单的数
 * blacklist.size()=m
 * 时间复杂度O(mlogm), 空间复杂度O(m)
 * **********/

class Solution {
private:
    int n, m;
    unordered_map<int, int> whitelist;
public:
    Solution(int n, vector<int>& blacklist){  //:n(n), blacklist(blacklist){}
        this->n = n;
        m = blacklist.size();
        sort(blacklist.begin(), blacklist.end());   //O(mlogm)
        if(m != 0){
            int j = 0, k = m-1, w=n-1, i = blacklist[0];
            //O(m)
            for(int r = 0;r < m && blacklist[r] < n-m;r++){
                i = blacklist[r];
                while(blacklist[k] == w){
                    --w;
                    --k;
                }
                whitelist[i] = w;
                --w;
            }
            srand((unsigned)time(NULL));
        }
    }
    
    int pick() {
        int randNum = rand() % (n - m);
        if(whitelist.find(randNum) == whitelist.end())
            return randNum;
        return whitelist[randNum];
    }
};

int main(){
    vector<int> blacklist = {2,1};
    Solution solution(4, blacklist);
    int a;
    a = solution.pick(); // 返回0，任何[0,1,4,6]的整数都可以。注意，对于每一个pick的调用，
                    // 0、1、4和6的返回概率必须相等(即概率为1/4)。
    a = solution.pick(); // 返回 4
    a = solution.pick(); // 返回 1
    a = solution.pick(); // 返回 6
    a = solution.pick(); // 返回 1
    a = solution.pick(); // 返回 0
    a = solution.pick(); // 返回 4
    return 0;
}