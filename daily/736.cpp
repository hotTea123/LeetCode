#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;


class Solution {
private:
    //找到匹配的括号
    int findSignelPos(string& s, int start=0){
        int signel = 1;
        for(int i=start;i < s.size();i++){
            if(s[i] == '(')
                ++signel;
            if(s[i] == ')')
                --signel;
            if(s[i] == ')' && signel == 0)
                return i;
        }
        return -1;
    }

    string read(string& s, int start){
        string st = "";
        int i;
        for(i=start;i < s.size();i++){
            if(s[i] == ' ' || s[i] == ')')
                break;
            st += s[i];
        }
        if(i < s.size())
            s = s.substr(i+1);
        else
            s = "";
        return st;
    }

    bool isNum(string& st){
        if(st[0] == '-' || (st[0] >= '0' && st[0] <= '9'))
            return true;
        return false;
    }

    int let(string& s, map<string, int> varNum){
        string str = "", key = "";
        int i = 0;
        while(s != ""){
            str = read(s, i);
            //表示还没有变量
            int j;
            string sub;
            if(str[0] == '('){
                j = findSignelPos(s);
                sub = s.substr(0, j);
            }
            
            if(key == ""){
                if(str == "(add"){
                    return addorMult(sub, varNum, true);
                }else if(str == "(mult"){
                    return addorMult(sub, varNum, false);
                }else if(str == "(let"){
                    return let(sub, varNum);
                }else{
                    key = str;
                }
            }else{
                if(str == "(add"){
                    varNum[key] = addorMult(sub, varNum, true);
                }else if(str == "(mult"){
                    varNum[key] = addorMult(sub, varNum, false);
                }else if(str == "(let"){
                    varNum[key] = let(sub, varNum);
                }else{
                    if(isNum(str))
                        varNum[key] = stoi(str);
                    else
                        varNum[key] = varNum[str]; 
                }
                key = "";
            }
            if(str[0] == '(')
                i = j + 2;
            else
                i = 0;
        }

        if(isNum(key))
            return stoi(key);
        else
            return varNum[key];
    }

    //op=true表示加，op=false表示乘
    int addorMult(string& s, map<string, int> varNum, bool op){
        string str = "", key = "";
        vector<int> nums;
        int i = 0;
        while(s != ""){
            str = read(s, i);
            int j;
            string sub;
            if(str[0] == '('){
                j = findSignelPos(s);
                sub = s.substr(0, j);
            }
            if(str == "(add"){
                nums.emplace_back(addorMult(sub, varNum, true));
            }else if(str == "(mult"){
                nums.emplace_back(addorMult(sub, varNum, false));
            }else if(str == "(let"){
                nums.emplace_back(let(sub, varNum));
            }else{
                if(isNum(str)){
                    nums.emplace_back(stoi(str));
                }else
                    nums.emplace_back(varNum[str]);
            }
            if(str[0] == '(')
                i = j + 2;
            else
                i = 0;
        }
        cout << nums.size() << endl;
        if(op)
            return nums[0] + nums[1];
        else
            return nums[0] * nums[1];
    }

public:
    int evaluate(string expression) {
        map<string, int> varNum;
        for(int i=0;i < expression.size();i++){
            string s = read(expression, i);
            int j = findSignelPos(expression);
            string sub = expression.substr(i, j-i);
            if(s == "(add")
                return addorMult(sub, varNum, true);
            if(s == "(mult")
                return addorMult(sub, varNum, false);
            if(s == "(let")
                return let(sub, varNum);
            i = j + 1;
        }
        return 0;
    }
};

int main(){
    //string expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    //string expression = "(let x 1 y 2 x (add x y) (add x y))";
    //string expression = "(let x 2 (add (let x 3 (let x 4 x)) x))";
    //string expression = "(let a1 3 b2 (add a1 1) b2)";
    string expression = "(let a -122 b 0 (add (add 1 -4) (mult a 66)))";
    //string expression = "(let x -2 y x y)";
    //string expression = "(let x 7 -12)";
    //string expression = "(let a (add 1 2) b (mult a 3) c 4 d (add a b) (mult d d))";
    int res = Solution().evaluate(expression);
    return 0;
}