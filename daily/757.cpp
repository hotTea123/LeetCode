#include<bits/stdc++.h>
using namespace std;

/*
    一道常规的需要分类讨论的题目，思路很好想，可是又有很多思虑不周的地方，如果没有错误显示，我估计我是不会知道自己
  哪儿错了的(好像分类讨论的题目我总是这样)，这次对于两个集合相交的情况我又想少了，以为只有边界条件相等这一种，殊不
  知还有{1,5}和[3,7]这样也有一个5是相交的而不是非要{1，5}和[5,7](好像挺明显的哦，可是为什么写的时候就没发现呢)。
    另外，对于sort中传第三个参数我又犯愁了，这次我想实现的是按二维数组的第二个元素大小排序，如果一样则第一个大的在
  前，第一次写二维数组的lamda函数，不会写，没想到这次函数的传参竟然是一维数组，所以不用捕获变量，传参的时候传一维
  的引用就可以了。
*/
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){  //a、b类型为vector<int>
            if(a[1] == b[1]) return a[0]>b[0];
            else return a[1]<b[1];});

        int max = -1, min = -1, res = 0;
        for(int i=0;i < intervals.size();i++){
            if(intervals[i][0] > max){
                //下一个集合与{min, max}没有相交的元素
                max = intervals[i][1];
                min = max -1;
                res += 2;
            }else if(intervals[i][0] > min){
                //这里之前想的太狭隘了，写成了intervals[i][0] == max
                //下一个集合与{min, max}有一个相交的元素,那个元素一定是max
                min = max;
                max = intervals[i][1];
                ++res;
            }
            //否则下一个集合包含了{min, max}，什么也不做
        }
        return res;
    }
};

int main(){
    vector<vector<int>> A = {{33,44},{42,43},{13,37},{24,33},{24,33},{25,48},{10,47},{18,24},{29,37},{7,34}};
    int res = Solution().intersectionSizeTwo(A);
    return 0;
}