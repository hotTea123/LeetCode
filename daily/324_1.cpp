#include<vector>
#include<algorithm>
using namespace std;

/* **********
 * 算法思想：先对数组进行排序，从中间位置划开可分为数组A和B两个，使用两个指针i/j分别指向数组A和B的末尾，
 然后往前移，新开一个数组依次循环放入A[i]和B[j]
 * 为什么要指向两个数组末尾？   考虑一种特殊情况，nums=[1,2,2,3]，如果都正向指的话结果为[2,2,1,3],即
 当数组中一半的元素为同一值的时候，则会出错
 * 时间复杂度O(nlogn), 空间复杂度O(n)
 * **********/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int numsLen = nums.size();
        int bound = (numsLen - 1) / 2;   //smallPos's max value
        int smallPos = bound;    
        int bigPos = numsLen - 1;         
        vector<int> temp = nums;         //O(n)
        sort(temp.begin(), temp.end());   //O(nlogn)
        int i = 0;
        //O(n)
        while(smallPos >= 0 && bigPos > bound){
            nums[i] = temp[smallPos];
            ++i;
            nums[i] = temp[bigPos];
            ++i;
            --smallPos;
            --bigPos;
        }
        if(smallPos == 0)
            nums[i] = temp[smallPos];

    }
};

int main(){
    Solution sovle;
    //vector<int> nums = {1,5,1,1,6,4};
    vector<int> nums = {1,3,2,2,3,1};
    //vector<int> nums = {1,2,2,3};

    sovle.wiggleSort(nums);
    return 0;
}