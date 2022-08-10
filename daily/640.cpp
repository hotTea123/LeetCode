#include<bits/stdc++.h>
using namespace std;

//2022.8.10每日一题
/* 
    又是需要处理这种式子的题，我自己感觉这次我处理的不错，只用了一个for循环，没有像之前一样while嵌套
  while(为了读取非个位数数字)，这次对于string的处理很清晰
*/
class Solution {
public:
    string solveEquation(string equation) {
        int left, right = 0;
        int leftx, rightx = 0;
        string str = "";
        for(auto ch:equation){
            if(ch =='+' || ch =='-' || ch == '='){
                if(str != ""){
                    right += stoi(str);
                    str = "";
                }
                if(ch == '-')
                    str += '-';
                else if(ch == '='){
                    left = right;
                    leftx = rightx;
                    right = 0;
                    rightx = 0;
                }
            }else if(ch == 'x'){
                if(str == "-")
                    --rightx;
                else if(str == "")
                    ++rightx;
                else
                    rightx += stoi(str);
                str = "";
            }else
                str += ch;
        }
        if(str != "")
            right += stoi(str);
        leftx -= rightx;
        right -= left;
        if(leftx == 0 && right == 0)
            return "Infinite solutions";
        if(leftx == 0 && right != 0)
            return "No solution";
        return "x="+to_string(right/leftx);
    }
};

int main(){
    string s = "x+5-3+x=6+x-2";
    string res = Solution().solveEquation(s);
    return 0;
}