#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int i;
        for(i=1;i < suits.size();i++){
            if(suits[i] != suits[0])
                break;
        }
        if(i == suits.size())
            return "Flush";
        map<int, int> r;
        for(auto i:ranks)
            r[i]++;
        if(r.size() == 2)
            return "Three of a Kind";
        if(r.size() == 3){
            for(auto i:r){
                if(i.second == 3)
                    return "Three of a Kind";
            }
            return "Pair";
        }
        if(r.size() == 4)
            return "Pair";
        return "High Card";
    }
};