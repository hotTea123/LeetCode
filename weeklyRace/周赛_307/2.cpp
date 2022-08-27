#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        bool isExsit = false;
        vector<int> cnt(10, 0);
        for(int i=0;i < num.size();i++){
            ++cnt[num[i]-'0'];
            if(num[i]-'0' != 0 && cnt[num[i]-'0'] == 2)
                isExsit = true;
        }
        string s = "";
        int maxNum = -1;
        for(int i=9;i >=0;i--){
            while(cnt[i] >=2 ){
                s += '0'+i;
                cnt[i] -= 2;
            }
            if(cnt[i] != 0)
                maxNum = max(maxNum, i);
        }
        if(!isExsit)
            return to_string(max(maxNum, 0));
        string sRev = s;
        reverse(sRev.begin(), sRev.end());
        if(maxNum == -1)
            return s+sRev;
        return s+to_string(maxNum)+sRev;
    }
};

int main(){
    string num = "000119";
    auto res = Solution().largestPalindromic(num);
    return 0;
}