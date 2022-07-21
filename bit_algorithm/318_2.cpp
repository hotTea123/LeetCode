#include<bits/stdc++.h>
using namespace std;

/*
    在1的基础上做了一点优化，将数组改成map，若两个单词对应同一个int则合并位1个
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> cnt;
        for(int i=0;i < words.size();i++){
            int key = 0;
            for(int j=0;j < words[i].size();j++){
                //把第words[i][j]-‘a’位 置1
                key |= (1 << (words[i][j]-'a'));
            }
            cnt[key] = max(cnt[key], int(words[i].size()));
        }

        int res = 0;
        for(auto [x1, y1]:cnt){
            for(auto [x2, y2]:cnt){
                if((x1 & x2) == 0)
                    res = max(res, y1*y2);
            }
        }
        return res;
    }
};
