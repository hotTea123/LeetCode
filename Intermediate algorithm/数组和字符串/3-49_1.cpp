#include<bits/stdc++.h>
using namespace std;

/*
    思路：将原数组复制到一个新数组中，并且在新数组中对每个小的字符串进行排序，如果是异位词他们排序后的
  字符串应该是一样的，再对所有的字符串进行大的排序，并且通过一个idx数组保存他们排序前的位置，这样就可
  对应到最初的数组各字符串的位置，在大的排序下，异位词永远会是相邻的，只要判断一个字符串跟它前一个字符
  串是否一样，如果一样则属于同一组，不一样则新开一组。
    注意：当你想向一个vector<vector>>中添加元素的时候，可以向下面这么做而不用使用一个额外的小vector
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<int> idx(n);
        for(int i=0;i < n;i++)
            idx[i] = i;
        vector<string> s(n);
        for(int i =0;i < n;i++){
            s[i] = strs[i];
            sort(s[i].begin(), s[i].end());
        }
        sort(idx.begin(), idx.end(), [&s](int x, int y){return s[x]<s[y];});
        vector<vector<string>> res;
        res.push_back({strs[idx[0]]});
        for(int i=1;i < n;i++){
            if(s[idx[i]] == s[idx[i-1]]){
                auto it = res.rbegin();
                it->emplace_back(strs[idx[i]]);  //注意这里使用->
            }else
                res.push_back({strs[idx[i]]});
        }
        return res;
    }
};

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(strs);
    return 0;
}