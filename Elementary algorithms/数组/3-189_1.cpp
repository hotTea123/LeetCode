#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        if(k >= n)
            k %= n;
        for(int i=0;i < n;i++)
            temp[i] = nums[i];
        for(int i=0;i < n;i++){
            int j = (i+k)%n;
            nums[j] = temp[i];
        }
    }
};