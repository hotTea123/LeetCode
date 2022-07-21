#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    int operate_nums(int a, int b, char op){
        if(op == '+')
            return a+b;
        if(op == '-')
            return a-b;
        return a*b;
    }

    vector<int> operate_vector(vector<int> a, vector<int> b, char op){
        vector<int> c;
        for(int i=0;i < a.size();i++){
            for(int j=0;j < b.size();j++){
                int r;
                if(op == '+')
                    r = a[i] + b[j];
                else if(op == '-')
                    r = a[i] - b[j];
                else
                    r = a[i] * b[j];
                c.emplace_back(r);
            }
        }
        return c;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        int expLen = expression.size();
        vector<int> nums;
        vector<char> ops;
        int i=0, j=0;
        while(j < expLen){
            string s = "";
            s += expression[j];
            ++j;
            while(j < expLen && expression[j] != '+' && expression[j] != '-' && expression[j] != '*'){
                s += expression[j];
                ++j;
            }
            nums.emplace_back(stoi(s));
            if(j == expLen)
                break;
            ops.emplace_back(expression[j]);
            ++j;
            ++i;
        }


        int numsLen = nums.size();
        vector<vector<vector<int>>>  dp(numsLen, vector<vector<int>>(numsLen));
        for(int t = 0;t < numsLen;t++){
            for(int i=0, j=i+t;j < numsLen;i++,j++){
                if(i == j)
                    dp[i][j].emplace_back(nums[i]);
                else if(i + 1 == j){
                    dp[i][j].emplace_back(operate_nums(nums[i], nums[j], ops[i]));
                }else{
                    for(int k = i;k < j;k++){
                        vector<int> c = operate_vector(dp[i][k], dp[k+1][j], ops[k]);
                        for(int l = 0;l < c.size();l++)
                            dp[i][j].emplace_back(c[l]);
                    }
                }
            }
        }
        return dp[0][numsLen-1];
    }
};

int main(){
    string expression = "2-1-1";
    vector<int> res = Solution().diffWaysToCompute(expression);
    return 0;
}