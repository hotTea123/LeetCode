#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//难题！dp的思路
class Solution {
private:
    bool updateDisAndCount(int i, vector<map<int, long>>& stationsDisAndCounts, vector<vector<int>>& stations, vector<long>& distance, vector<int>& countPos){
        bool flag = false;
        for(int j = i-1;j >= 0;j--){
            vector<int> delet_key;
            for (auto k = stationsDisAndCounts[j].rbegin(); k != stationsDisAndCounts[j].rend(); k++){
                if(k->second >= stations[i-1][0]){
                    flag = true;
                    int dis = k->second + stations[i-1][1];
                    int count = k->first + 1;
                    if(dis > distance[count]){
                        stationsDisAndCounts[i][count] = dis;
                        if(distance[count] != 0){
                            //shan chu
                            int deleteStation = countPos[count];
                            delet_key.emplace_back(count);
                            delet_key.emplace_back(deleteStation);
                        }
                        distance[count] = dis;
                        countPos[count] = i;
                    }
                }
            }
            for(int m=0;m<delet_key.size();m++){
                int count = delet_key[m];
                ++m;
                stationsDisAndCounts[delet_key[m]].erase(count);
            }
        }
        return flag;
    }

public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stationsLen = stations.size();
        //到达各个加油站各count-dis
        vector<map<int, long>> stationsDisAndCounts(stationsLen+1);
        vector<long> distance(stationsLen+1, 0);  //distance[i]表示加i次油最多能行驶的路程
        vector<int> countPos(stationsLen+1);         //加每次油所对应的stationsDisAndCounts中的位置，表示stationsDisAndCounts[i]
        stationsDisAndCounts[0][0] = startFuel;
        distance[0] = startFuel;
        countPos[0] = 0;
        int i;
        for(i = 1;i < stationsLen+1;i++){
            //某个加油站的起始位置已经大于target了
            if(stations[i-1][0] > target){
                ++i;
                break;
            }
            bool isUpdate = updateDisAndCount(i, stationsDisAndCounts, stations, distance, countPos);
            if(isUpdate == false)
                break;
        }
        
        for(i = 0;i < stationsLen+1;i++){
            if(distance[i] >= target)
                break;
        }
        if(i == stationsLen+1 && distance[i-1] < target)
            return -1;
        return i;
    }    
};

int main(){
    // int target = 25, startFuel = 15;
    // vector<vector<int>> stations = {{10,5},{15,1},{16,1},{17,3},{20,5}};

    int target = 1000, startFuel = 83;
    vector<vector<int>> stations = {{47,220},{65,1},{98,113},{126,196},{186,218},{320,205},{686,317},{707,325},{754,104},{781,105}};

    //
    // int target = 1000000000, startFuel = 1000000000;
    // vector<vector<int>> stations = {{5,1000000000},{1000,1000000000},{100000,1000000000}};

    // int target = 999, startFuel = 1000;
    // vector<vector<int>> stations = {{5,100},{997,100},{998,100}};
    
    // int target = 100, startFuel = 1;
    // vector<vector<int>> stations = {{10,100}};

    int res = Solution().minRefuelStops(target, startFuel, stations);
    return 0;
}