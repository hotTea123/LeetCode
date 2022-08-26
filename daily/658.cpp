#include<bits/stdc++.h>
using namespace std;

// 2022.8.25每日一题， 时间复杂度O(n)
   ///TODO:如果使用二分，时间复杂度可以降到O(logn)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, j = k;
        int pre = -1;
        while(j < arr.size()){
            if(arr[j] == arr[i]){
                if(pre == -1)
                    pre = i;
                else{
                    if(abs(arr[pre]-x) <= abs(arr[i]-x) && arr[pre] != arr[i]){
                        i = pre;
                        break;
                    }else
                        pre = i;
                }
            }
            else if(abs(arr[j]-x) >= abs(arr[i]-x))
                break;
            ++i;
            ++j;
        }
        vector<int> res(k);
        for(int r=0;r < k;r++, i++)
            res[r] =  arr[i];
        return res;
    }
};