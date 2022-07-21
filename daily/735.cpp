#include<bits/stdc++.h>
using namespace std;

//主要是读懂题意，然后直接模拟
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0;i<asteroids.size();i++){
            if(s.empty() || s.top() < 0 || asteroids[i]*s.top() > 0){
                s.push(asteroids[i]);
                continue;
            }
            while(!s.empty()){
                if(abs(s.top()) < abs(asteroids[i]) && asteroids[i]*s.top() < 0)
                    s.pop();
                else
                    break;
            }
            if(s.empty() || s.top() < 0)
                s.push(asteroids[i]);
            else if(s.top() == -asteroids[i])
                s.pop();
        }

        int resLen = s.size();
        vector<int> res(resLen);
        for(int i=resLen-1;i >=0;i--){
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};