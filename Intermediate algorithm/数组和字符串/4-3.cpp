#include<bits/stdc++.h>
using namespace std;

//双指针
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, cnt = 0;
        unordered_set<char> chs;
        int i = 0, j = 0;
        while(i < s.size()){
            if(chs.find(s[i]) == chs.end())
                chs.insert(s[i]);
            else{
                while(s[i] != s[j]){
                    chs.erase(s[j]);
                    ++j;
                }
                ++j;
            }
            res = max(res, i-j+1);
            ++i;
        }
        return res;
    }
};

int main(){
    string s = "abba";
    int res = Solution().lengthOfLongestSubstring(s);
    return 0;
}