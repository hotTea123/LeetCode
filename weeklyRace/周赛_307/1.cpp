#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int res = 0;
        for(int i=0;i < experience.size();i++){
            if(initialEnergy <= energy[i]){
                res += energy[i] - initialEnergy+1;
                initialEnergy = energy[i] + 1;
            }
            initialEnergy -= energy[i];
            if(initialExperience <= experience[i]){
                res += experience[i] - initialExperience +1;
                initialExperience = experience[i]+1;
            }
            initialExperience += experience[i];
        }
        return res;
    }
};