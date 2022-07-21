#include<bits/stdc++.h>
using namespace std;

//解法一：并查集
/*
    遍历每个数，在hash表中找是否存在比他大1的数，如果存在，则把当前数的父节点设为比他大1的数
    时间复杂度O(n)，只需要遍历3遍数组，空间复杂度O(n)，开了两个跟数组一样大的map
*/
class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
public:
    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void uni(int x, int y){
        if(find(x) == find(y))
            return;
        int xp = find(x), yp = find(y);
        parent[xp] = yp;
        rank[yp] += rank[xp];
    }

    int longestConsecutive(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            parent[nums[i]] = nums[i];
            rank[nums[i]] = 1;
        }
        for(auto x:parent){
            if(parent.find(x.first+1) != parent.end()){
                uni(x.first, parent[x.first+1]);
            }
        }
        int res = 0;
        for(auto x:parent){
            if(x.first == x.second)
                res = max(rank[x.first], res);
        }
        return res;
    }
};