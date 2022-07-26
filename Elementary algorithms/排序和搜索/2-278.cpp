#include<bits/stdc++.h>
using namespace std;

/*
    明显的二分题，关于二分需要注意的两点：
    1.high = mid还是high = mid-1，low = mid还是low = mid+1,
        关键在于判断mid能不能是最终答案，二分中你要永远保证答案在[low, high]中，两边都是闭区间
    2.mid = (low+high)/2 还是 mid = (low+high+1)/2
      两种的区别是你要取的是满足条件的第一个元素还是最后一个元素，例如：对于[1,4]你想取>2的第一个元素，则不加1，
    如果你想取小于3的最后一个元素，则需要加1。
    3.mid = (low+high)/2有可能发生int越界(c++中)，此时可以取low+(high-low)/2
        mid = (low+high+1)/2 对应于 low+(high-low+1)/2
*/

class Solution {
private:
    bool isBadVersion(int version);
public:
    int firstBadVersion(int n) {
        long long low = 1, high = n, mid;
        while(low < high){
            mid = (low+high)/2;
            //mid = low+(high-low)/2; 则不用long long类型了
            if(isBadVersion(mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};