#include<bits/stdc++.h>
using namespace std;

/*
符合条件的出现次数只能有两种：
1.出现种类为1
①每个数出现次数为1
②就一个数出现多次
2.出现种类为2
①多的出现次数 = 少的出现次数+1，且多的出现次数的数为1
②少的出现次数为1， 且少的出现次数的数为1
*/

// 2022.8.18每日一题
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> cnt, cntCnt;
        int res = 1, maxcnt = 0, mincnt = nums.size();
        for(int i=0;i < nums.size();i++){
            bool flag = false;
            ++cnt[nums[i]];
            if(cnt[nums[i]] != 1){
                --cntCnt[cnt[nums[i]]-1];
                if(cntCnt[cnt[nums[i]]-1] == 0)
                    cntCnt.erase(cnt[nums[i]]-1);
            }
            ++cntCnt[cnt[nums[i]]];
            maxcnt = max(maxcnt, cnt[nums[i]]);
            if(maxcnt == 1 || cnt.size() == 1)   //maxcnt==1表示每个数出现一次，cnt.size()==1表示就一个数
                flag = true;
            else if(cntCnt.size() == 2){
                auto it1 = cntCnt.begin();
                it1++;
                auto it2 = it1;
                it1 = cntCnt.begin();
                if(it1->first > it2->first || (it1->first == it2->first && it1->second > it2->second)){
                    auto temp = it1;
                    it1 = it2;
                    it2 = temp;
                }
                if((it1->first == 1&& it1->second==1) || (it1->first+1 == it2->first && it2->second == 1))
                flag = true;
            }
            if(flag)
                res = i+1;
        }
        return res;
    }
};


int main(){
    vector<int> nums = {1,1,1,2,2,2,3,3,3};
    int res = Solution().maxEqualFreq(nums);
    return 0;
}
