#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    pair<string, int> read(string& sentence, int pos){
        int i = pos;
        string s = "";
        while(sentence[i] != ' '&&i < sentence.size()){
            s += sentence[i];
            i++;
        }            
        return make_pair(s, i);
    }

    bool isSubstr(string& A, string a){
        for(int i=0;i < a.size();i++){
            if(A[i] != a[i])
                return false;
        }
        return true;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> dic;
        for(int i=0;i < dictionary.size();i++)
            dic.insert(dictionary[i]);
        int i = 0;
        string ans = "", s;
        while(i < sentence.size()){
            auto sPos = read(sentence, i);
            i = sPos.second+1;
            s = sPos.first;
            string sAdd = s, comp = "";
            for(int j=0;j < s.size()-1;j++){
                comp += s[j];
                auto pos = dic.lower_bound(comp);
                if(pos != dic.end() && *pos == comp){
                    sAdd = comp;
                    break;
                }
            }
            if(ans == "")
                ans = sAdd;
            else
                ans += ' ' + sAdd;
        }
        return ans;
    }
};

int main(){
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "cattle rattled by the battery";
    string ans = Solution().replaceWords(dictionary, sentence);
    return 0;
}