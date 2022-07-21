#include<bits/stdc++.h>
using namespace std;

//暴力枚举
class MagicDictionary {
private:
    vector<string> dic;
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        dic = dictionary;
    }

    bool search(string searchWord) {
        for(string s:dic){
            if(s.size() != searchWord.size())
                continue;
            int diff = 0;
            for(int i=0;i < s.size();i++){
                if(s[i] != searchWord[i])
                    ++diff;
                if(diff > 1)
                    break;
            }
            if(diff == 1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
