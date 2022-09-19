#include <bits/stdc++.h>
using namespace std;

// 2022.9.13 每日一题
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string newS = s;
        sort(newS.begin(), newS.end(), greater<char>());
        int idx = -1;
        for(int i=0;i < s.size();i++){
            if(s[i] != newS[i]){
                idx = i;
                break;
            }
        }
        if(idx == -1)
            return num;
        for(int i=s.size()-1;i >=0;i--){
            if(s[i] == newS[idx]){
                swap(s[i], s[idx]);
                break;
            }
        }
        return stoi(s);
    }
};

int main(){
    int res = Solution().maximumSwap(983685);
    return 0;
}