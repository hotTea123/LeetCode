#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int preTime = 0;
        bool preState = true;   //start为true
        stack<int> funcs;
        vector<int> res(n, 0);
        for(auto log:logs){
            string s = "";
            bool isEnd = false;
            int func;
            for(int i=0;i < log.size();i++){
                if(log[i] == ':'){
                    if(s == "start"){
                        s = "";
                        continue;
                    }else if(s == "end"){
                        isEnd = true;
                    }else{
                        func = stoi(s);
                    }
                    s = "";
                }else
                    s += log[i];
            }
            int time = stoi(s);
            if(!isEnd){
                if(!funcs.empty()){
                    res[funcs.top()] += time - preTime;
                    if(!preState)
                        --res[funcs.top()];
                }
                funcs.push(func);
                preState = true;
            }else{
                res[func] += time - preTime;
                if(preState)
                    ++res[func];
                funcs.pop();
                preState = false;
            }
            preTime = time;
        }
        return res;
    }
};

int main(){
    //vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<string> logs = {"0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"};
    vector<int> res = Solution().exclusiveTime(3, logs);
    return 0;
}