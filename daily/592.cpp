#include<bits/stdc++.h>
using namespace std;

/*
    又是表达式类的题目，这一类型一直是我的痛点，这是也是不例外的debug了很久(在力扣页面上debug)
    思想很常规，直接模拟就可以，把所有分子存入一个数组，分母存入一个数组，因为他这里只有加减法，而又有
  负数，因此可把所有操作都看成加法，-i不过是加(-1)而已
    代码错误
    1.在执行gcd没有作符号处理，负数执行gcd会出问题->解决：修改了约分的逻辑，确保都是正数
    2.pair的返回值如果想用[a,b]的形式拿到，似乎必须新声明一个变量去储存
    3.在读取表达式转换为分子分母的数组的时候也出现了一些问题，如分割不当等
*/

class Solution {
private:
    vector<int> up, down;

    int gcd(int a, int b){
        if(a < b)
            swap(a,b);
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }

    pair<int, int> simple(int a, int b){
        bool isNeg = false;
        if(a<0)
            isNeg = true;
        a = abs(a);
        //确保作gcd的都是正数
        int fac = gcd(a,b);
        a /= fac;
        b /= fac;
        if(isNeg)
            a = -a;
        return make_pair(a, b);
    }
public:
    string fractionAddition(string expression) {
        int i=0;
        bool isUp = true;
        while(i < expression.size()){
            if(expression[i] == '/' || expression[i] == '+'){
                ++i;
                continue;
            }
            string num = "";
            if(expression[i] == '-'){
                ++i;
                num += '-';
            }
            while(i < expression.size() && expression[i] >= '0' && expression[i] <= '9'){
                num += expression[i];
                ++i;
            }
            if(isUp)
                up.emplace_back(stoi(num));
            else
                down.emplace_back(stoi(num));
            isUp = !isUp;
        }

        int lcm = 1;
        long long sum = 0;
        for(int i=0;i < down.size();i++){
            if(down[i] < 0 && up[i] < 0)
                up[i] = abs(up[i]);
            else if(down[i] < 0 || up[i] < 0)
                up[i] = -abs(up[i]);
            down[i] = abs(down[i]);

            int a = lcm;
            lcm *= down[i]/gcd(down[i], lcm);
            sum *= lcm/a;
            sum += up[i]*lcm/down[i];

            auto x = simple(sum, lcm);
            sum = x.first;
            lcm = x.second;
        }
        return to_string(sum)+'/'+to_string(lcm);
    }
};