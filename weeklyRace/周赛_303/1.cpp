#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> isApp(26, false);
        for(char i:s){
            if(isApp[i-'a'] == true)
                return i;
            isApp[i-'a'] = true;
        }
        return 0;
    }
};