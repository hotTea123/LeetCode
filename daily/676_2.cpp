#include<bits/stdc++.h>
using namespace std;

//字典树,e...,理论上时间复杂度应该更低，但实际运行时间并没有降下来，不知道为什么
class MagicDictionary {
private:
    struct Trie{
        bool isEnd;
        vector<Trie*> children;

        Trie():isEnd(false), children(vector<Trie*>(26, nullptr)) {}

        void insert(string word){
            Trie* node = this;
            for(int i=0;i < word.size();i++){
                if(node->children[word[i]-'a'] == nullptr)
                    node->children[word[i]-'a'] = new Trie();
                node = node->children[word[i]-'a'];
            }
            node->isEnd = true;
        }

    };
    Trie trie;

public:
    void buildDict(vector<string> dictionary) {
       for(int i=0;i < dictionary.size();i++)
            trie.insert(dictionary[i]);
    }

    bool searchword(Trie* node, string word, bool changed, int start){
        if(start == word.size()){
            if(node->isEnd && changed)
                return true;
            else
                return false;
        }
        if(node->children[word[start]-'a'] == nullptr && changed)
            return false;

        //true可以马上返回，false不行
        for(int i=0;i < 26;i++){
            if(node->children[i] != nullptr){
                if(!changed && i != word[start]-'a'){
                    if(searchword(node->children[i], word, !changed, start+1))
                        return true;
                }else if(i == word[start]-'a'){
                    if(searchword(node->children[i], word, changed, start+1))
                        return true;
                }
            }
        }
        return false;
    }

    bool search(string searchWord) {
        bool res = searchword(&trie, searchWord, 0, 0);
        return res;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main(){
    MagicDictionary* obj = new MagicDictionary();
    vector<string> dictionary = {"hello","hallo","leetcode"};
    obj->buildDict(dictionary);
    bool param_2 = obj->search("hello");
    return 0;
}
