#include<bits/stdc++.h>
using namespace std;

/*
    思想题
    思路：如果你能得到一个长度为k的骰子，则每个数的第k-1个后面必须还有所有的n个数
    于是只需要遍历nums,每轮回一次1~n的所有数，则可得到的骰子长度+1，统计1~n出现的次数
*/
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int res = 1;
        set<int> nums;
        for(int i:rolls){
            nums.insert(i);
            if(nums.size() == k){
                nums.clear();
                res++;
            }
        }
        return res;
    }
};