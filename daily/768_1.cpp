#include<bits/stdc++.h>
using namespace std;

/*
    延续769的思路，排序后记录每个数第一次出现的索引，关键在于对重复的数的处理
    维护一个cnt变量，表示不包含最大数的其余数出现次数+1(最大数)-1(计数从0开始)，也就是最大数只会计算
  一次数量，而其余的数有重复的要计算多次，每次出现新的最大数只需要让cnt =i表示之前遍历过的所有数相加，
  最后如果cnt >= 最大数第一次出现的索引则可以让res+1
  ？？？？必须是>=?还是可以==？？？
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> a = arr;
        sort(a.begin(), a.end());
        unordered_map<int, int> idx;
        for(int i=0;i < arr.size();i++){
            if(i > 0 && a[i] == a[i-1])
                continue;
            idx[a[i]] = i;
        }
        int res = 0, maxNum = -1, cnt;
        for(int i=0;i < arr.size();i++){
            if(arr[i] < maxNum)
                ++cnt;
            else if(arr[i] > maxNum){
                cnt = i;
                maxNum = arr[i];
            }
            if(cnt >= idx[maxNum])
                ++res;
        }
        return res;
    }
};

int main(){
    //vector<int> arr = {1,1,0,0,1};
    vector<int> arr = {2,1,3,4,4};
    //vector<int> arr = {4,6,19,6,4,13,4,1,2,14,1,18,8,12,19,11,0,14,12,13};
    int res = Solution().maxChunksToSorted(arr);
    return 0;
}