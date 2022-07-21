#include<vector>
#include<algorithm>
using namespace std;

/* **********
 * 算法思想：324_1中的sort使得整个算法的时间复杂度提升到了nlogn，但是只要找到排序后位置处于中间的那个数mid，
 由此数将数组划分为A/B两部分，且A中所有数小于等于mid，B中所有数大于等于mid即可，A和B中元素是否有序并不需要
 关心
 * 如何解决324_1中所说的特殊情况？   即需要再分别遍历一遍A,B，把与mid相等的数拿到mid的周围，如对于找到mid后
 的数组[2,1,2,|2|,4,2,3], 需要调整为[1,2,2,|2|,4,3,2]
 * 时间复杂度O(n), 空间复杂度O(n)
 * **********/

/* **********
 * 新函数：nth_element(start, mid, end)
 将数组[start, end)上第mid大位置的数放在mid位置，其中mid左边的数比mid小，mid右边的数比mid大(类似于快速排序的一次结果)
 mid是一个迭代器类型
 * **********/


class Solution {
private:
    void sortMid(vector<int>& arr, int i, int j) {
        int bound = (arr.size() - 1) / 2;
        while(i < j){
            if(arr[i] == arr[bound] && arr[j] != arr[bound]){
                swap(arr[i], arr[j]);
                ++i;
                --j;
            }else if(arr[i] == arr[bound] && arr[j] == arr[bound]){
                --j;
            }else if(arr[i] != arr[bound] && arr[j] != arr[bound]){
                ++i;
            }else{
                ++i;
                --j;
            }
        }
    }
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> arr = nums;         //O(n)
        int numsLen = nums.size();
        auto mid = arr.begin() + (numsLen-1) / 2;
        /*----------------nth_element-------------------------------*/
        nth_element(arr.begin(), mid, arr.end());    //O(n)

        int bound = (numsLen - 1) / 2;   //smallPos's max value        
        //O(n),
        sortMid(arr, 0, bound-1);
        sortMid(arr, bound+1, numsLen-1);

        int smallPos = bound;    
        int bigPos = bound + 1; 
        //O(n)
        int i = 0;
        while(smallPos >= 0){
            nums[i] = arr[smallPos];
            ++i;
            --smallPos;
            if(i == numsLen)
                break;
            nums[i] = arr[bigPos];
            ++i;
            ++bigPos;
        }
    }
};

int main(){
    Solution sovle;
    //vector<int> nums = {1,5,1,1,6,4};
    //vector<int> nums = {1,3,2,2,3,1};
    //vector<int> nums = {1,2,2,3};
    //vector<int> nums = {1};
    vector<int> nums = {2,1,2,4,2,3};
    sovle.wiggleSort(nums);
    return 0;
}