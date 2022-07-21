#include<bits/stdc++.h>
using namespace std;

/*
    思路：并查集，将等于1的(i, j)跟等于1的(i-1, j)和(i, j-1)相连
*/
class UnionFindSet{
private:
    vector<int> parent;
    vector<int> rank;
    int n;
    int count;

public:
    UnionFindSet(int m, int n){
        parent = vector<int>(m*n);
        rank = vector<int>(m*n, 1);
        for(int i=0;i < m*n;i++)
            parent[i] = i;
        count = 0;
        this->n = n;
    }

    //返回当前节点的根节点
    int Find(int x){
        if(parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    //连接x，y
    void Union(int x, int y, int a, int b){
        int x1 = x*n + y;
        int x2 = a*n + b;
        int xParent = Find(x1), yParent = Find(x2);
        if(xParent == yParent)
            return;
        if(rank[xParent] > rank[yParent]){
            parent[yParent] = xParent;
            rank[xParent] += rank[yParent];
        }else{
            parent[xParent] = yParent;
            rank[yParent] += rank[xParent];
        }
        int c = max(rank[xParent], rank[yParent]);
        count = max(count, c);
    }

    int getRank(int i, int j){
        return rank[i*n + j];
    }

    void setRank(int i, int j, int a){
        rank[i*n+j] = a;
        count = max(count, a);
    }

    int getCount(){
        return count;
    }

};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFindSet set(m, n);
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    set.setRank(i, j, 1);
                    if(i > 0 && grid[i-1][j] == 1)
                        set.Union(i, j, i-1, j);
                    if(j > 0 && grid[i][j-1] == 1)
                        set.Union(i, j, i, j-1);
                }
            }
        }
        return set.getCount();
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1},{1,1,1}};
    int res = Solution().maxAreaOfIsland(grid);
    return 0;
}