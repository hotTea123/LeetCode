#include<bits/stdc++.h>
using namespace std;

//302场周赛
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> count(101,0);
        int c=0, rest = 0;
        for(int i=0;i < nums.size();i++)
            count[nums[i]]++;
        for(int i=0;i < count.size();i++){
            c += count[i] / 2;
            if(count[i] % 2 != 0)
                rest++;
        }
        return {c, rest};
    }
};

int main(){
    vector<int> nums = {1,3,2,1,3,2,2};
    vector<int> res = Solution().numberOfPairs(nums);
    return 0;    
}