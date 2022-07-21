#include<bits/stdc++.h>
using namespace std;

/*
    一个int有32位，小写字母一共只有26个，因此可用一个int位标志一个单词中某个字母是否出现，当两个单词对应的
  int取且运算==0时则代表两个单词没有相同字母。
    编码时要注意max的两个参数类型必须一样，而s.size()的返回值是unsigned int
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> cnt(words.size(), 0);
        for(int i=0;i < words.size();i++){
            for(int j=0;j < words[i].size();j++){
                //把第words[i][j]-‘a’位 置1
                cnt[i] |= (1 << (words[i][j]-'a'));
            }
        }

        int res = 0;
        for(int i=0;i < words.size();i++){
            for(int j=i+1;j < words.size();j++){
                if((cnt[i] & cnt[j]) == 0){
                    int len = words[i].size()*words[j].size();
                    res = max(res, len);
                }
            }
        }
        return res;
    }
};
