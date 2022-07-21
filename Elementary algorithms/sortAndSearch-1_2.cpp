#include<vector>
using namespace std;

//时间复杂度为 O(m + n),空间复杂度为O(1)
//从后往前
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=n-1, j=m-1, k=m+n-1;
        while()



        
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