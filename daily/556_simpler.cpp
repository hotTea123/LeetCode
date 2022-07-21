#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXINT 2147483647

class Solution {
private:
    int GreaterElement(vector<int>& nums){
        int resIndex = 0; 
        pair<int, int> minGreaterPos(nums.size(), 0);

        int i, j;
        for(i=0;i < nums.size() - 1;i++){
            for(j=i+1;j < nums.size();j++){
                if(nums[i] > nums[j]){
                    if(j < minGreaterPos.first){
                        minGreaterPos.first = j;
                        minGreaterPos.second = i;
                        resIndex = j;
                    }
                    break;
                }
            }
        }
        if(resIndex != 0)
            swap(nums[minGreaterPos.first], nums[minGreaterPos.second]);
        return resIndex;
    }


public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        //取到每一位数
        while(n != 0){
            nums.emplace_back(n % 10);
            n /= 10;
        }

        //找到下一个更大数应该交换的那一位
        int resIndex = GreaterElement(nums);
        if(resIndex == 0)
            return -1;

        //截断更大数应该的调换的那一位的后面的数，取最小值
        sort(nums.begin(), nums.begin()+resIndex, greater<int>());

        vector<int> lessNums(resIndex);
        for(int i=0;i < resIndex;i++)
            lessNums[i] = nums[i];
        sort(lessNums.rbegin(), lessNums.rend());

        long long res = nums[nums.size()-1];
        for(int i = nums.size()-2;i >= 0;i--){
            res *= 10;
            res += nums[i];
        }

        if(res > MAXINT)
            return -1;

        return res;
    }
};