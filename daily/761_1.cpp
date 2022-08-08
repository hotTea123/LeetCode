#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findSpecial(string& s, int i, int j){
        //以j开始的特殊二进制序列要比以i开始的大，否则返回-1
        vector<int> cnt(2, 0);
        bool comp = false;
        while(j < s.size()){
            if(i != -1){
                if(!comp && s[j] < s[i])
                    return -1;
                if(s[j] > s[i])
                    comp = true;
                ++i;
            }
            ++cnt[s[j]-'0'];
            if(cnt[1] < cnt[0])
                return -1;
            else if((comp || i == -1) && cnt[1] == cnt[0])
                return j;
            ++j;
        }
        return -1;
    }

    bool swapStr(string& s){
        for(int i=0;i < s.size()-1;i++){
            int j = findSpecial(s, -1, i);
            if(j == -1)
                continue;
            //找到以j+1开始的且比以i开始的更大的特殊二进制序列
            int k = findSpecial(s, i, j+1);
            if(k != -1){
                string temp = s;
                s = temp.substr(0, i)+temp.substr(j+1, k-j)+temp.substr(i, j-i+1)+temp.substr(k+1);
                return true;
            }
        }
        return false;
    }
public:
    string makeLargestSpecial(string s) {
        while(1){
            if(!swapStr(s))
                break;
        }
        return s;
    }
};

int main(){
    string s = "101010";
    //string s= "11011001110000";
    s = Solution().makeLargestSpecial(s);
    return 0;
}