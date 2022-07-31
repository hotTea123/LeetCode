#include<bits/stdc++.h>
using namespace std;

/*
    又是一道脑筋急转弯的题，要满足人数递增，则最好的就是每次加一个人，因此分成2份至少需要3个成绩，分成
  3分至少需要6(1+2+3)个成绩；
    对于n个人，如果n=1+2+...+i，将数组排序后我们可发现，只要第一个取n-i那个数，之后每次只要从n-i右边
  拿一个数，左边从第一个数开始拿，拿到这一份共需要的成绩数，那么一定可满足每份之和递增，所以只需要求出
  i即可
*/
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int i = 1, res = 0;
        while(n >= 0){
            n -= i;
            if(n >= 0){
                ++i;
                ++res;
            }
        }
        return res;  
    }
};