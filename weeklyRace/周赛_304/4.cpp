#include<bits/stdc++.h>
using namespace std;

/*
    从一个点开始，一直访问它指向的下一个点，直到没有下一个(egdes[i]==-1)或者出现了环
    用一个dis标志从某个点i开始到其他他所能到达的点的距离，并且只访问那些dis还未被标记的点，就算是对于
  2->1，先访问并标记1，再访问并标记2也不会出现问题，因为没有出现环我们不关心，但我们绝不能在判断环里
  面通过dis是否等于1来判断，因为dis!=-1只是表示这个点曾经被访问过，但它有可能并不是在这个连通分量里
  面被访问的，因此对于每个连通分量我们都重置isVisit用于判断是否出现环
*/

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int res = -1, len =0;
        vector<int> dis(edges.size(), -1);
        vector<bool> isVisit(edges.size());
        for(int i=0;i < edges.size();i++){
            if(dis[i] == -1){
                int node = i, d = 1;
                fill(isVisit.begin(), isVisit.end(), false);
                while(1){
                    dis[node] = d;
                    isVisit[node] = true;
                    ++len;
                    if(edges[node]==-1)
                        break;
                    if(isVisit[edges[node]]){
                        //出现环
                        res = max(res, dis[node]-dis[edges[node]]+1);
                        break;
                    }
                    ++d;
                    node = edges[node];
                    if(len == edges.size())
                        break;
                }
            }
            if(len == edges.size())
                break;
        }
        return res;
    }
};

int main(){
    vector<int> edges = {1,0};
    int res = Solution().longestCycle(edges);
    return 0;
}