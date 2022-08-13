#include<bits/stdc++.h>
using namespace std;

/*
    使用类似单调栈，当一个新的元素来时，如果他是最大的，直接放在后面作为一个新的块，否则他需要
  合并到之前的某个块，将这个数依次和单调栈里面的数比较，直到>其中的数，这样就找到了它需要和哪些
  块合并，再把最初单调栈末尾的数放进去。
    单调栈的含义是：例如 3,6  表示第一个块从0~3，第二个块从3~6
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> monostack;
        for(int num:arr){
            if(monostack.empty() || num >= monostack.top()){
                monostack.push(num);
            }else{
                int maxNum = monostack.top();
                while(!monostack.empty() && num < monostack.top())
                    monostack.pop();
                monostack.push(maxNum);
            }
        }
        return monostack.size();
    }
};

int main(){
    //vector<int> arr = {1,1,0,0,1};
    vector<int> arr = {2,1,3,4,4};
    //vector<int> arr = {4,6,19,6,4,13,4,1,2,14,1,18,8,12,19,11,0,14,12,13};
    int res = Solution().maxChunksToSorted(arr);
    return 0;
}