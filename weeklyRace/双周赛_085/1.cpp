#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=k;
        int cnt=0, minWhiteBlocks;
        for(int j=0;j < i;j++){
            if(blocks[j] == 'W')
                ++cnt;
        }
        minWhiteBlocks = cnt;
        while(i < blocks.size()){
            if(blocks[i-k] == 'W')
                --cnt;
            if(blocks[i] == 'W')
                ++cnt;
            minWhiteBlocks = min(minWhiteBlocks, cnt);
            ++i;
        }
        return minWhiteBlocks;
    }
};