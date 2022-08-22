#include<bits/stdc++.h>
using namespace std;

//二分
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low < high){
            mid = (low+high)/2;   
            if((mid == 0 || nums[mid] > nums[mid-1]) && 
                (mid == n-1 || nums[mid] > nums[mid+1]))
                return mid;
            else if((mid == 0 || nums[mid] > nums[mid-1]) && 
                    (mid == n-1 || nums[mid] < nums[mid+1]))
                low = mid + 1;
            else
                high = mid -1 ;
        }
        return low;
    }
};
