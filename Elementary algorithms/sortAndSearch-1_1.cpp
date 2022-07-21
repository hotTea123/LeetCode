#include<vector>
using namespace std;

//时间复杂度为 O(m + n),空间复杂度为O(m)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, k=0;
        vector<int> nums3 = nums1;
        while(i < m && j < n){
            if(nums3[i] <= nums2[j]){
                nums1[k] = nums3[i];
                ++i;
            }else{
                nums1[k] = nums2[j];
                ++j;
            }
            ++k;
        }
        while(i < m){
            nums1[k] = nums3[i];
            ++i;
            ++k;
        }
        while(j < n){
            nums1[k] = nums2[j];
            ++j;
            ++k;
        }
    }
};



int main(){
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m = 3, n = 3;
    Solution().merge(nums1, m, nums2, n);
    return 0;
}