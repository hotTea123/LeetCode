#include<bits/stdc++.h>
using namespace std;

void translate(string& s){
    for(int i=0;i<s.size();i++){
        if(s[i] == '[')
            s[i] = '{';
        else if(s[i] == ']')
            s[i] = '}';
    }
}


int main(){
    string s = "[[9,10],[9,10],[4,5],[-9,-3],[-9,1],[0,3],[6,10],[-5,-4],[-7,-6]]";

    translate(s);
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}