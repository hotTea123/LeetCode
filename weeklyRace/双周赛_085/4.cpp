#include<bits/stdc++.h>
using namespace std;

class UnionFindSet{
private:
    vector<int> parent;
    vector<int> nums;
    vector<long long> sum;
    long long maxSum;
public:
    UnionFindSet(int n){
        parent = vector<int>(n);
        nums = vector<int>(n, 0);
        sum = vector<long long>(n);
        maxSum = 0;
        for(int i=0;i < n;i++)
            parent[i] = i;
    }

    //返回当前节点的根节点
    int Find(int x){
        if(parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    //连接x，y
    void Union(int x, int y){
        int xParent = Find(x), yParent = Find(y);
        if(xParent == yParent)
            return;
        parent[xParent] = yParent;
        sum[yParent] += sum[xParent];
        maxSum = max(maxSum, sum[yParent]);
    }

    void add(int idx, long long num){
        nums[idx] = num;
        sum[idx] = num;
        if(idx > 0 && nums[idx-1] != 0)
            Union(idx, idx-1);
        if(idx < nums.size()-1 && nums[idx+1] != 0)
            Union(idx, idx+1);
        maxSum = max(maxSum, num);
    }

    long long getMaxsum(){
        return maxSum;
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<bool> isVisit(n, false);
        UnionFindSet ufs(n);
        vector<long long> res(n);
        res[n-1] = 0;
        for(int i=n-1;i > 0;i--){
            int idx = removeQueries[i];
            ufs.add(idx, nums[idx]);
            res[i-1] = ufs.getMaxsum();
        }
        return res;
    }
};