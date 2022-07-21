#include<bits/stdc++.h>
using namespace std;

/*
    并查集思路：k从1开始增大，那么threshold/k则会减小，用index存储nums排序后的索引，从最大的数开始
  遍历，将他左右满足>threshold/k的数合并，并判断合并后的rank值是否大于k
*/
class UnionFindSet{
public:
    vector<int> parent;
    vector<int> rank;

    UnionFindSet(int n){
        for(int i=0;i < n;i++){
            parent.emplace_back(i);
            rank.emplace_back(1);
        }
    }

    //返回当前节点的根节点
    int Find(int x){
        if(parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    //把x连接到y上
    void Union(int x, int y){
        int xParent = Find(x), yParent = Find(y);
        if(xParent == yParent)
            return;
        if(rank[xParent] > rank[yParent]){
            parent[yParent] = xParent;
            rank[xParent] += rank[yParent];
        }else{
            parent[xParent] = yParent;
            rank[yParent] += rank[xParent];
        }
    }
};

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> index(n);
        for(int i=0;i<n;i++)
            index[i] = i;
        sort(index.begin(), index.end(), [&nums](int x, int y){return nums[x]>nums[y];});
        UnionFindSet set(n);
        int pos = 0;
        for(int k=1;k <= n;k++){
            int minValue = threshold / k;
            for(int i=pos;i < index.size();i++){
                if(nums[index[i]] <= minValue){
                    pos = i;
                    break;
                }
                //左边
                if(index[i]>0 && nums[index[i]]>minValue && nums[index[i]-1]>minValue)
                        set.Union(index[i]-1, index[i]);
                //右边
                if(index[i]<nums.size()-1&&nums[index[i]]>minValue && nums[index[i]+1]>minValue)
                    set.Union(index[i], index[i]+1);
                if(set.rank[set.Find(index[i])] >= k)
                    return k;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {818,232,595,418,608,229,37,330,876,774,931,939,479,884,354,328};
    int threshold = 3790;
    int res = Solution().validSubarraySize(nums, threshold);
    return 0;
}