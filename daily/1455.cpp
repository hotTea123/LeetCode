#include<bits/stdc++.h>
using namespace std;

// 2022.8.21  每日一题
class Solution {
private:
    bool judge(string& s, string& searchWord){
        if(s.size() < searchWord.size())
            return false;
        for(int i=0;i < searchWord.size();i++){
            if(searchWord[i] != s[i])
                return false;
        }
        return true;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s = "";
        int cnt = 1;
        for(auto ch:sentence){
            if(ch == ' '){
                if(judge(s, searchWord))
                    return cnt;
                ++cnt;
                s = "";
            }else
                s += ch;
        }
        if(judge(s, searchWord))
            return cnt;
        return -1;
    }
};