#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
            'q','r','s','t','u','v','w','x','y','z'};
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size(), 0);
        for(int i=0;i < shifts.size();i++){
            int num = shifts[i][2] == 0 ? -1:1;
            diff[shifts[i][0]] += num;
            if(shifts[i][1]+1 < s.size())
                diff[shifts[i][1]+1] -= num;
        }
        int sum = 0;
        for(int i=0;i < s.size();i++){
            sum += diff[i];
            s[i] = (s[i]-'a'+sum) % 26;
        }
        return s;
    }
};

int main(){
    string s = "ksztajnymer";
    vector<vector<int>> shifts = {{4,9,1},{2,5,1},{7,9,0},{6,10,0},{1,7,1},{0,7,1},{0,3,0},{3,3,1},{7,9,0},{7,7,0},{6,7,0},{7,9,0},{3,9,0},{10,10,1},{8,9,0},{6,9,1},{1,2,1},{3,9,0},{8,10,1},{4,7,1},{9,10,1},{8,9,0},{5,8,0},{8,9,1},{0,7,1},{2,2,1},{8,8,1},{3,7,0},{1,10,1},{9,9,1},{4,9,0},{5,6,1},{7,8,1},{8,9,0},{7,7,1},{9,9,1}};
    auto res = Solution().shiftingLetters(s, shifts);
    return 0;
}