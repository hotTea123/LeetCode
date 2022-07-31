#include<bits/stdc++.h>
using namespace std;

/*
    计算出两个点能到达的点和对应的距离，存放到vector中，再比较两个vector是否在某一点都能到达，存储
  较长的那个距离，比较所有能到达的点的较长的距离，取最小值
    提交错误原因：
    1.因为我的nodeNum初始值是n(节点编号是0~n-1)，如果没有一样的能到达的点应该返回-1而不是n可是我直
  接无脑返回了nodeNum
*/
class Solution {
public:
    vector<int> findV(vector<int>& edges, int node){
        int n = edges.size();
        vector<int> v(n, -1);
        v[node] = 0;
        int dis = 1;
        while(1){
            if(edges[node] == -1 || v[edges[node]] != -1)
                break;
            v[edges[node]] = dis;
            ++dis;
            node = edges[node];
        }
        return v;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> v1 = findV(edges, node1);
        vector<int> v2 = findV(edges, node2);
        int nodeNum = n, dis = n;
        for(int i=0;i <n;i++){
            if(v1[i] != -1 && v2[i] != -1){
                int d = max(v1[i], v2[i]);
                if(dis == d)
                    nodeNum = min(nodeNum, i);
                else if(d < dis){
                    dis = d;
                    nodeNum = i;
                }
            }
        }
        if(nodeNum == n)
            return -1;
        return nodeNum;
    }
};

int main(){
    vector<int> edges = {5,4,5,4,3,6,-1};
    int res = Solution().closestMeetingNode(edges, 0, 1);
    return 0;
}