#include<bits/stdc++.h>
using namespace std;

//map中存已经被删除的那些正整数
class SmallestInfiniteSet {
private:
    set<int> smallerase;
public:
    int popSmallest() {
        int res = 1;
        auto n = smallerase.begin();
        while(*n == res){
            ++n;
            ++res;
        }
        smallerase.insert(res);
        return res;
    }
    
    void addBack(int num) {
        if(smallerase.find(num) != smallerase.end())
            smallerase.erase(num);
    }
};
