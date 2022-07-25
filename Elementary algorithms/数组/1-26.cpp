#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsLen = nums.size();
        int i=0, j=0, k=j+1;
        while(k < numsLen){
            if(nums[j] == nums[k]){
                ++k;
            }else{
                ++i;
                nums[i] = nums[k];
                j = k;
                ++k;
            }
        }
        return i+1;
    }
};

int main(){
    Solution sovle;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int n = sovle.removeDuplicates(nums);
    return 0;
}