#include<bits/stdc++.h>
using namespace std;

/*
    模拟题，问题在于如何求出乱序数组中第i小的数的索引
    可以直接排序，至于如何保存原来的索引有两种方法，一种是将数和索引用pair保存，一种是定义一个index数组
  排序这个index数组重写他的sort方法(可使用lamda函数/可直接声明一个返回值为bool的函数/可定义一个结构体，
  重写他的()方法)，另：使用lamda函数或者函数时，对于数组/map等数据结构一定要传引用减少他的copy次数
*/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int numLen = nums[0].size();
        vector<vector<string>> newNums(nums[0].size(), vector<string>(nums.size(), ""));
        vector<vector<int>> index(nums[0].size(), vector<int>(nums.size()));
        for(int k=0;k < queries.size();k++){
            int n = queries[k][1]-1;
            if(newNums[n][0] != ""){
                ans.emplace_back(index[n][queries[k][0]-1]);
                continue;
            }
            for(int i=0;i < nums.size();i++){
                newNums[n][i] = nums[i].substr(numLen-n-1);
                index[n][i] = i;
            }

            sort(index[n].begin(), index[n].end(), [&newNums, n](int x, int y){
                if(newNums[n][x] == newNums[n][y])
                    return x<y;
                return newNums[n][x]<newNums[n][y];
            });
            ans.emplace_back(index[n][queries[k][0]-1]);
        }
        return ans;
    }
};

int main(){
    //vector<string> nums = {"64333639502","65953866768","17845691654","87148775908","58954177897","70439926174","48059986638","47548857440","18418180516","06364956881","01866627626","36824890579","14672385151","71207752868"};
    //vector<vector<int>> queries = {{9,4},{6,1},{3,8},{12,9},{11,4},{4,9},{2,7},{10,3},{13,1},{13,1},{6,1},{5,10}};
    // vector<string> nums = {"7062852270146477248296527","8433780701670054260678760","8699421879227760163019849","7708276868930722275669591","5074829025635016047494703","5896327888048068611168261","7260190089159791786288449","5781138574494763732963172","3205437840168891808107684","5391561242659929681878939","9291899334089749518212291","8708326599236172552237668","3618812336262173046978703","4807369922822632937475631","0316892108136392839378991","8367705082821693868985331","2107315678805939657548178","9907244113601275760502412","4677127508895251971677534","1439698519575527518052264","2511775183710951968637133"};
    // vector<vector<int>> queries = {{6,2}};
    vector<string> nums = {"24","37","96","04"};
    vector<vector<int>> queries = {{2,1},{2,2}};
    vector<int> ans = Solution().smallestTrimmedNumbers(nums, queries);
    return 0;
}