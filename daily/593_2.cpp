#include<bits/stdc++.h>
using namespace std;

/*
    每条边都一样长，对角线是边的根号二倍长
*/
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> squre(4);
        squre[0] = p1;
        squre[1] = p2;
        squre[2] = p3;
        squre[3] = p4;
        sort(squre.begin(), squre.end(), [](auto& x, auto& y){
            if(x[0]==y[0])
                return x[1]<y[1];
            return x[0]<y[0];});
        int edgeStd = pow(squre[1][1]-squre[0][1],2)+pow(squre[1][0]-squre[0][0],2);
        if(!edgeStd)
            return false;
        for(int i=0;i < 3;i++){
            for(int j=i+1;j < 4;j++){
                int edge = pow(squre[i][1]-squre[j][1],2)+pow(squre[i][0]-squre[j][0],2);
                if(edge != edgeStd && edge != 2*edgeStd)
                    return false;
            }
        }
        return true;
    }
};


int main(){
    vector<int> p1 = {1,0}, p2 = {-1, 0}, p3= {0,1}, p4={0,-1};
    //vector<int> p1 = {1,2}, p2 = {2, 1}, p3= {0,0}, p4={2,0};
    bool res = Solution().validSquare(p1, p2, p3, p4);
    return 0;
}