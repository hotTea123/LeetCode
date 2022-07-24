#include<bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    struct comp{
        bool operator()(const pair<string, int>& x, const pair<string,int>& y)const{
            if(x.second == y.second)
                return x.first < y.first;
            return x.second > y.second;
        }
    };
    unordered_map<string, string> kinds;
    unordered_map<string, int> rate;
    unordered_map<string, set<pair<string, int>, comp>> res;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i < foods.size();i++){
            kinds[foods[i]] = cuisines[i];
            rate[foods[i]] = ratings[i];
            res[cuisines[i]].insert(make_pair(foods[i],ratings[i]));
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = kinds[food];
        res[cuisine].erase(make_pair(food, rate[food]));
        res[cuisine].insert(make_pair(food, newRating));
        rate[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return res[cuisine].begin()->first;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */