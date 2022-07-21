#include<bits/stdc++.h>
using namespace std;

//word 和 prefix 仅由小写英文字母组成
class Trie {
private:
    bool isEnd;
    vector<Trie*> children;

public:
    Trie(): isEnd(false), children(vector<Trie*>(26, nullptr)){}


    void insert(string word) {
        Trie* node = this;
        for(int i=0;i < word.size();i++){
            if(node->children[word[i]-'a'] == nullptr){
                node->children[word[i]-'a'] = new Trie();
            }
            node = node->children[word[i]-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(int i=0;i < word.size();i++){
            if(node->children[word[i]-'a'] == nullptr){
                return false;
            }
            node = node->children[word[i]-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i=0;i < prefix.size();i++){
            if(node->children[prefix[i]-'a'] == nullptr){
                return false;
            }
            node = node->children[prefix[i]-'a'];
        }
        return true;
    }
};


int main(){
    Trie trie;
    bool res;
    trie.insert("apple");
    res = trie.search("apple");   
    res = trie.search("app");     
    res = trie.startsWith("app"); 
    trie.insert("app");
    res = trie.search("app");
    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */