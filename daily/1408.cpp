#include<bits/stdc++.h>
using namespace std;

/*
    c++ string中的find是采用朴素实现，时间复杂度O(mn)
    可通过第二个参数指定从某个位置开始查找
    返回值：找到的子串的首字符位置，或若找不到这种子串则为s.npos
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(int i=0;i < words.size();i++){
            for(int j=0; j < words.size();j++){
                if(i == j)
                    continue;
                if(words[j].find(words[i]) != words[j].npos){
                    res.emplace_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};