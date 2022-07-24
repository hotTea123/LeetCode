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
    string s = "[[33,44],[42,43],[13,37],[24,33],[24,33],[25,48],[10,47],[18,24],[29,37],[7,34]]";

    translate(s);
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}