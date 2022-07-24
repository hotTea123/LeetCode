#include<bits/stdc++.h>
using namespace std;

//思路不难，但是在分类讨论（条件的划分）上又debug了好久
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        map<int, int> diff;
        long long k = k1 + k2;
        for(int i=0;i<n;i++){
            int d = abs(nums1[i]-nums2[i]);
            diff[d]++;
        }
        while(k > 0){
            auto iter = prev(diff.end(), 1);
            if(diff.size() == 1 && k >= iter->first*iter->second)
                return 0;
            auto next = prev(diff.end(), 2);
            if(diff.size() == 1 || k <= (iter->first - next->first)*iter->second){
                long long a = k / iter->second;
                long long b = k % iter->second;
                if(a != 0){
                    diff[iter->first-a] += iter->second - b;
                    diff[iter->first] = 0;
                }else
                    diff[iter->first] -= b;
                diff[iter->first-a-1] += b;
                break;
            }else{
                k -= (iter->first - next->first)*iter->second;
                next->second += iter->second;
                diff.erase(iter->first);
            }
        }
 
        long long res = 0;
        for(auto i:diff){
            res += i.second * pow(i.first, 2);
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {1,4,10,12}, nums2 = {5,8,6,9};
    int k1 = 1, k2 = 1;
    int res = Solution().minSumSquareDiff(nums1, nums2, k1, k2);
    return 0;
}