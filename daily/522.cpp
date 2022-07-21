#include<vector>
#include<string>
using namespace std;


//如果一个字符串的子串是特殊序列，那么这个字符串也是特殊序列
//对于任意两个字符串，判断字符串i是否是字符串j的子串,如果不是，则返回i的长度
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        int strCount = strs.size();
        bool flag;
        for(int i = 0;i < strCount;i++){
            flag = true;
            int  substrLen = strs[i].size();
            for(int j = 0;j < strCount;j++){
                if(j == i)
                    continue;
                //判断strs[i]是否是strs[j]的子串
                int m=0, n=0;
                while(m<substrLen && n < strs[j].size()){
                    if(strs[i][m] == strs[j][n]){
                        ++m;
                        ++n;
                    }else{
                        ++n;
                    }
                }
                //strs[i] is substr of strs[j]
                if(m == substrLen){
                    flag = false;
                    break;
                }
            }

            //strs[i] is not any substr of other str
            if(flag == true)
                maxLen = max(maxLen, substrLen);
        }
        return maxLen;
    }
};

int main(){
    Solution sovle;
    //vector<string> strs = {"aba","cdc","eae"};
    //vector<string> strs = {"aaa","aaa","aa"};
    vector<string> strs = {"aabbcc", "aabbcc","cb"};

    int res = sovle.findLUSlength(strs);
    return 0;
}