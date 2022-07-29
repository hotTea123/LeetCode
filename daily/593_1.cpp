#include<bits/stdc++.h>
using namespace std;

/*
    如何判断四个点组成的是否是正方形？
    1.两条对角线的中点相同->是平行四边形  //最开始并没有注意这一点
    2.在1的基础上，对角线长度相同->是矩形
    3.在1的基础上，对角线垂直->是菱形
    4.同时具有2.3的条件->是正方形
    此外，还需要对正方形各个点作排序以区分对角顶点
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

        if(squre[3][1]+squre[0][1] != squre[1][1]+squre[2][1])
            return false;
        if(squre[3][0]+squre[0][0] != squre[1][0]+squre[2][0])
            return false;

        int k1 = pow(squre[0][1]-squre[3][1], 2)+ pow(squre[0][0]-squre[3][0], 2);
        int k2 = pow(squre[1][1]-squre[2][1], 2)+ pow(squre[1][0]-squre[2][0], 2);
        if(k1 != k2 || k1==0)
            return false;

        int edge;

        k1 = (squre[3][1]-squre[0][1])*(squre[2][1]-squre[1][1]);
        k2 = (squre[3][0]-squre[0][0])*(squre[2][0]-squre[1][0]);
        if(!k1 && !k2)
            return true;
        if(k2 != 0 && k1/k2==-1)
            return true;
        return false;
    }
};

int main(){
    vector<int> p1 = {1,0}, p2 = {-1, 0}, p3= {0,1}, p4={0,-1};
    //vector<int> p1 = {1,2}, p2 = {2, 1}, p3= {0,0}, p4={2,0};
    bool res = Solution().validSquare(p1, p2, p3, p4);
    return 0;
}