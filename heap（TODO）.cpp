#include<bits/stdc++.h>
using namespace std;

//大根堆
class heap{
private:
    vector<int> heapVec;
public:
    void init(vector<int>& vals){
        heapVec = vals;
        for(int i=vals.size()-1;i > 0;i--){
            if(heapVec[i] > heapVec[(i-1)/2])
                swap(heapVec[i], heapVec[(i-1)/2]);
        }
    }

    void push(int val){
        heapVec.emplace_back(val);
        int i=heapVec.size()-1;
        while(i > 0){
            if(heapVec[i] > heapVec[(i-1)/2])
                swap(heapVec[i], heapVec[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int top(){
        if(heapVec.size())
            return heapVec[0];
        return -1;
    }

    void pop(){
        swap(heap)
    }

    int size(){
        return heapVec.size();
    }
};