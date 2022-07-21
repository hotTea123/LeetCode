#include<bits/stdc++.h>
using namespace std;

//使用前缀树实现
class Trie {
private:
    bool isEnd;
    vector<Trie*> children;

public:
    Trie(): isEnd(false), children(vector<Trie*>(26, nullptr)){}


    void insert(string word) {
        Trie* node = this;
        for(int i=0;i < word.size();i++){
            if(node->isEnd)
                return;
            if(node->children[word[i]-'a'] == nullptr){
                node->children[word[i]-'a'] = new Trie;
            }
            node = node->children[word[i]-'a'];
        }
        node->isEnd = true;
    }
    
    string searchPrefix(string word) {
        Trie* node = this;
        string res = "";
        for(int i=0;i < word.size();i++){
            if(node->isEnd)
                return res;
            if(node->children[word[i]-'a'] == nullptr)
                return word;
            res += word[i];
            node = node->children[word[i]-'a'];
        }
        return res;
    }
};


class Solution {
private:
    Trie trie;

    pair<string, int> read(string& sentence, int pos){
        int i = pos;
        string s = "";
        while(sentence[i] != ' '&&i < sentence.size()){
            s += sentence[i];
            i++;
        }            
        return make_pair(s, i);
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> dic;
        for(int i=0;i < dictionary.size();i++)
            trie.insert(dictionary[i]);
        int i = 0;
        string s, ans = "";
        while(i < sentence.size()){
            auto sPos = read(sentence, i);
            i = sPos.second+1;
            s = sPos.first;
            string sAdd = trie.searchPrefix(s);
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