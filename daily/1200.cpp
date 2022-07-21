#include<vector>
#include<algorithm>
using namespace std;

//简单题
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int minAbsDiffer = arr[1]-arr[0];
        for(int i=1;i < arr.size();i++){
            int diff = arr[i] - arr[i-1];
            if(diff < minAbsDiffer ){
                minAbsDiffer = diff;
                res.clear();
                res.push_back({arr[i-1], arr[i]});
            }else if(diff == minAbsDiffer){
                res.push_back({arr[i-1], arr[i]});
            }
        }
    }
};