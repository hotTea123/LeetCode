#include<unordered_map>
#include<string>
using namespace std;

//无聊的一题
//substr(pos, len) 两个参数都有默认值，pos不指定默认全数组，len不指定默认从pos位置到数组末尾的长度

class Solution {
private:
    int id;
    unordered_map<int, string> itos_database;
    string prefix;
    int prefixLen;
public:
    Solution(){
        id = 198;
        prefix = "http://tinyurl.com/";
        prefixLen = prefix.size();
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        ++id;
        itos_database[id] = longUrl;
        return prefix + to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int shortId = stoi(shortUrl.substr(prefixLen));
        return itos_database[shortId];
    }
};

int main(){
    Solution sovle;
    string longUrl = "https://leetcode.com/problems/design-tinyurl";
    string shortid = sovle.encode(longUrl);
    shortid = sovle.encode(longUrl);
    string longid = sovle.decode(shortid);
    return 0;
}