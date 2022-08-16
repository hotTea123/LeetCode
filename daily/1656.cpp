#include<bits/stdc++.h>
using namespace std;

//2022.8.16  每日一题
class OrderedStream {
private:
    vector<string> stream;
    int ptr;
public:
    OrderedStream(int n) {
        ptr = 0;
        stream = vector<string>(n, "");
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey-1] = value;
        if(idKey-1 != ptr)
            return {};
        vector<string> res;
        while(ptr < stream.size() && stream[ptr] != ""){
            res.emplace_back(stream[ptr]);
            ++ptr;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */