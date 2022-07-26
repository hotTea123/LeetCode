class Solution {
public:
    int hammingDistance(int x, int y) {
        //异或再求1的数目
        x ^= y;
        //现在问题变成了求1个数的二进制中含有多少个1
        int res = 0, lowbit;
        while(x > 0){
            lowbit = x & (-x);
            x &= ~lowbit;
            ++res;
        }
        return res;
    }
};