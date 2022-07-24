#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int len = target.size();
        //判断字符及出现顺序是否一样
        int i=0, j=0;
        while(j < len){
            if(target[j] == '_'){
                ++j;
                continue;
            }
            while(i < len && start[i] == '_')
                ++i;
            if(target[j] != start[i])
                return false;
            ++i;
            ++j;
        }
        while(i < len){
            if(start[i] != '_')
                return false;
            ++i;
        }

        i=0, j=0;
        while(j < len){
            //找到L/R的位置
            if(target[j] == '_'){
                ++j;
                continue;
            }     
            while(i < len){
                if(start[i] == '_'){
                    ++i;
                    continue;
                }
                if(start[i] == 'L'){
                    if(i < j)
                        return false;
                    swap(start[i],start[j]);
                    ++i;
                    ++j;
                    break;
                }else if(start[i] == 'R'){
                    if(i > j)
                        return false;
                    if(i == j){
                        ++i;
                        ++j;
                        break;
                    }
                    while(i < j){
                        int k=i+1;
                        if(start[k] == 'L')
                            return false;
                        if(start[k] == '_'){
                             while(start[k] == '_'){
                                ++k;
                            }
                            swap(start[i], start[k-1]);
                            i = k-1;
                            continue;
                        }
                        while(start[k] == 'R'){
                            ++k;
                        }
                        if(start[k] == 'L')
                            return false;
                        swap(start[i], start[k]);
                        ++i;
                    }
                    ++i;
                    ++j;
                    break;
                }
            }
        }
        return true;
    }
};

int main(){
    string start = "_L__R__R_L", target = "L______RR_";
    bool res = Solution().canChange(start, target);
    return 0;
}