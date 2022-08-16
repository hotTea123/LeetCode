#include<bits/stdc++.h>
using namespace std;

class A{
public:
    A(){}
    void func(){
        cout << "A.func" << endl;
    }

    virtual void func1(){
        cout << "A.func" << endl;
    }
};

class B: public A{
public:
    B(){}
    void func(){
        cout << "B.func" << endl;
    }

    void func1(){
        cout << "B.func" << endl;
    }
};

int main(){
    A a = A();
    a.func();
    a = B();
    a.func();
    return 0;
}