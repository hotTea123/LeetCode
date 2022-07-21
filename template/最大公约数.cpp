#include<bits/stdc++.h>
using namespace std;

 //(a,b)和(b,a mod b)的公约数一样，其中b为a/b中较小的那个数
int gcd(int a,int b){
    if(a < b)
        swap(a, b);
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
