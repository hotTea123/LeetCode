#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

//fgsjfigosrjfdskfudhasreicbksdjkfejpa
//时间复杂度O(n)，空间复杂度O(m) m=26
class Solution {
public:
    int firstUniqChar(string s) {
        char count[26]={0};
        unordered_map<char, int> charSort;
        for(int i = 0;i < s.size();i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a'] == 1){
                charSort[s[i]] = i;
            }else{
                if(charSort.find(s[i]) != charSort.end())
                    charSort.erase(s[i]);
            }
        }
        int firstAppear = -1;
        for(auto& n:charSort){
            if(firstAppear == -1)
                firstAppear = n.second;
            else
                firstAppear = min(n.second, firstAppear);
        }
        return firstAppear;
    }
};

int main(){
    string s = {"fgsjfigosrjfdskfudhasreicbksdjkfejpa"};
    int res = Solution().firstUniqChar(s);
    return 0;
}