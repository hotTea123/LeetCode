#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    int GreaterElement(vector<int>& nums){
        int resIndex = -1; 
        pair<int, int> minGreaterPos(-1, 0);

        int i, j;
        for(i=nums.size()-1;i > 0;i--){
            for(j=i-1;j >= 0;j--){
                if(nums[i] > nums[j]){
                    if(j > minGreaterPos.first){
                        minGreaterPos.first = j;
                        minGreaterPos.second = i;
                        resIndex = j;
                    }
                    break;
                }
            }
        }
        if(resIndex != -1)
            swap(nums[minGreaterPos.first], nums[minGreaterPos.second]);
        return resIndex;
    }


public:
    void nextPermutation(vector<int>& nums) {
        //找到下一个更大数应该交换的那一位
        int resIndex = GreaterElement(nums);
        if(resIndex == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        

        //截断更大数应该的调换的那一位的后面的数，取最小值
        sort(nums.begin()+resIndex+1, nums.end());
        return;
    }
};

int main(){
    vector<int> nums = {1,2};
    Solution().nextPermutation(nums);
    return 0;
}