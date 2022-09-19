#include <bits/stdc++.h>
using namespace std;

// 2022.9.4 每日一题
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        unordered_set<int> rows;
        int res = 0;
        for(int i=0;i < m;i++){
            bool flag = false;
            for(int j=0;j < n;j++){
                if(!flag && mat[i][j] == 1)
                    flag = true;
                else if(flag && mat[i][j] == 1){
                    flag = false;
                    break;
                }
            }
            if(flag)
                rows.insert(i);
        }
        for(int j=0;j < n;j++){
            bool flag = false;
            int r=-1;
            for(int i=0;i < m;i++){
                if(!flag && mat[i][j] == 1){
                    flag = true;
                    r = i;
                }else if(flag && mat[i][j] == 1){
                    flag = false;
                    break;
                }
            }
            if(flag && rows.find(r) != rows.end())
                ++res;
        }
        return res;
    }
};