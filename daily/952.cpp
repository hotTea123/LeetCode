#include<bits/stdc++.h>
using namespace std;

class UnionFindSet{
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    UnionFindSet(int n, int m){
        parent = vector<int>(n+m);
        rank = vector<int>(n+m, 0);
        for(int i=0;i < n+m;i++){
            parent[i] = i;
            if(i < n)
                rank[i] = 1;
        }
        count = 1;
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
        if(rank[xParent] > rank[yParent]){
            parent[yParent] = xParent;
            rank[xParent] += rank[yParent];
        }else{
            parent[xParent] = yParent;
            rank[yParent] += rank[xParent];
        }
        int a = max(rank[xParent], rank[yParent]);
        count = max(count, a);
    }

    int getCount(){
        return count;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxNum+1, true);
        map<int, int> fac;
        int k=0;
        for(int i=2;i <= maxNum;i++){
            if(isPrime[i]){
                fac[i] = k;
                ++k;
            }
            for(auto [f, _]:fac){
                if(i*f>maxNum)
                    break;
                isPrime[i*f] = false;
                if(i % f == 0)
                    break;
            }
        }
        UnionFindSet ufs(nums.size(), fac.size());
        for(int i=0;i<nums.size();i++){
            for(auto [f, j]:fac){
                if(f*f>nums[i]){
                    break;
                }
                if(nums[i] % f ==0)
                    ufs.Union(i, j+nums.size());
                while(nums[i] % f ==0)
                    nums[i] /= f;
                if(nums[i] == 1)
                    break;
            }
            if(nums[i] != 1)
                ufs.Union(i, fac[nums[i]]+nums.size());
        }
        return ufs.getCount();
    }
};

int main(){
    vector<int> nums = {4,6,15,35};
    int res = Solution().largestComponentSize(nums);
    return 0;
}