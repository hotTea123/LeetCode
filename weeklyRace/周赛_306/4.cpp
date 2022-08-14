#include<bits/stdc++.h>
using namespace std;

/*
    对任意数，假设有n位，分为两部分求：
    1.所有1位、2位...n-1位的特殊整数
    这些数因为位数比n位小，所以求的时候数字没有限制,可以任取，求k位的特殊整数，答案为9*A(9, k-1),
  第一位不能取0只有9个数，后面k-1位除去第一位后还有9个数可以进行全排列
    2.求n位的特殊整数
    采用从左到右依次确定第i位的数的方法，对于第i位，数字为k的数而言，那么第i位只能取小于k或者等于k且
  之前还未出现过的数，如果取小于k那么第i位后面的数仍可以随便取，采用全排列求出，如果取第i位为k，那么
  对i+1位如法炮制

*/
class Solution {
private:
    int computeA(int n, int m){
        int res = 1;
        for(int i=0;i < m;i++){
            res *= n;
            --n;
        }
        return res;
    }
public:
    int countSpecialNumbers(int n) {
        string num = "";
        int res = 0;
        while(n > 0){
            if(num != "")
                res += 9 * computeA(9, num.size()-1);
            num = to_string(n % 10) + num;
            n /= 10;
        }
        n = num.size();
        unordered_set<int> nums;
        for(int i=0;i < n;i++){
            int t = num[i]-'0';
            if(i == 0)   //第一位不能取0
                --t;
            if(i == n-1)  //最后一位能取到num[i]-'0'
                ++t;
            for(auto a:nums){
                if((i < n -1 && a < num[i]-'0') || (i == n-1 && a<= num[i]-'0'))
                    --t;
            }
            res += t*computeA(9-i, n-i-1);
            int sz = nums.size();
            nums.insert(num[i]-'0');
            if(nums.size() == sz)
                break;
        }
        return res;
    }
};

int main(){
    int res = Solution().countSpecialNumbers(10);
    return 0;
}