#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> squre(4);
        squre[0] = p1;
        squre[1] = p2;
        squre[2] = p3;
        squre[3] = p4;
        vector<double> k;
        vector<int> len;
        for(int i=0;i<3;i++){
            for(int j=i;j < 4;j++){
                if(squre[i][0] != squre[j][0] && squre[i][1] != squre[j][1]){
                    if(k.size() == 2)
                        return false;
                    k.emplace_back((double)(squre[i][1]-squre[j][1])/(squre[i][0]-squre[j][0]));
                    len.emplace_back(pow(squre[i][1]-squre[j][1], 2)+pow(squre[i][0]-squre[j][0], 2));
                }
            }
        }
        if(k[0]*k[1] == -1 && len[0]==len[1])
            return true;
        return false;
    }
};

int main(){
    vector<int> p1 = {1,0}, p2 = {-1, 0}, p3= {0,1}, p4={0,-1};
    bool res = Solution().validSquare(p1, p2, p3, p4);
    return 0;
}