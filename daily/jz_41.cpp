#include<bits/stdc++.h>
using namespace std;

class MovingAverage {
private:
    int nextPos;
    double sum;
    int count;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        nextPos = 0;
        sum = 0;
        count = 0;
        nums.resize(size);
        fill(nums.begin(), nums.end(), 0);
    }
    
    double next(int val) {
        count = min(count+1, int(nums.size()));
        sum -= nums[nextPos];
        sum += val;
        nums[nextPos] = val;
        nextPos = (nextPos+1) % nums.size();
        return (sum / double(count));
    }
};