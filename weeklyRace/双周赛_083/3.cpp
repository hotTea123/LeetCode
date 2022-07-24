#include<bits/stdc++.h>
using namespace std;

class NumberContainers {
private:
    unordered_map<int, int> num;  //存某个索引的数
    unordered_map<int, set<int>> hash;   //存某个元素位置集合
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(num.find(index) != num.end())
            hash[num[index]].erase(index);
        num[index] = number;
        hash[number].insert(index);
    }
    
    int find(int number) {
        if(hash.find(number) == hash.end() || hash[number].empty())
            return -1;
        return *hash[number].begin();
    }
};

int main(){
    NumberContainers numberContain;
    numberContain.change(2, 10);
    numberContain.change(1, 10);
    numberContain.change(3, 10);
    numberContain.change(5, 10);
    numberContain.change(1, 20);
    return 0;
}