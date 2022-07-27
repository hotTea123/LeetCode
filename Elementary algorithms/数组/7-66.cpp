#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = true;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]+flag == 10)
                digits[i] = 0;
            else{
                if(flag)
                    ++digits[i];
                flag = false;
            }                
        }
        if(flag)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};