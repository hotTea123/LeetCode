#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, set<int>> lenSet;
        for(int i=0;i < nums.size();i++){
            bool flag = false;
            for(auto& len:lenSet){
                for(auto& n:len.second){
                    if(nums[i] > n){
                        int newlen = len.first+1;
                        len.second.erase(n);
                        lenSet[newlen].insert(nums[i]);
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(!flag)
                lenSet[1].insert(nums[i]);
        }
        return lenSet.begin()->first;
    }
};

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int res = Solution().lengthOfLIS(nums);
    return 0;
}