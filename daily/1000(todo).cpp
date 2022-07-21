#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int stoneLen = stones.size();
        if(stoneLen == 1)
            return 0;
        if(k != 2 && (stoneLen+1)%k != 0)
            return -1;
        if(stoneLen < k)
            return -1;
        return merge(stones, k, 0, stoneLen-1);
    }

    int merge(vector<int>& stones, int k, int start, int end){
        int minCost = 0;
        if(end - start == k-1){
            for(int i = start;i <= end;i++)
                minCost += stones[i];
            return minCost;
        }

        vector<int> split(k-1);
        //把start, end 拆成k个部分，且每个部分要么是一个数，要么能被k合并
        for(int i = start+1, t=0;t < k;i++, t++){
            
            int cost = 0, temp = 0;
            for(int j = start;j < i;j++){
                cost += stones[j];
                ++temp;
            }
            int j = end;
            while(temp < k-1){
                cost += stones[j];
                --j;
                ++temp;
            }


            if( i != j)
                cost += 2 * merge(stones, k, i, j);
            else
                cost += stones[i];

            if(minCost == 0)
                minCost = cost;
            else
                minCost = min(minCost, cost);
        }
        return minCost;
    }
};

int main(){
    Solution sovle;
    vector<int> stones = {3,2,4,1};
    int k = 2;
    int res = sovle.mergeStones(stones, k);
    return 0;
}