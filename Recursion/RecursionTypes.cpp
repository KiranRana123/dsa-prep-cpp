#include<bits/stdc++.h>
using namespace std;

/*
Two types of recursion:
1) Parameterised : we use a parameter to store answer for each recursion call.
2) Functional: no parameter is used.
*/

//Parameterised
//sum1toN

int sum1toNParam(int i, int sum)
{
    if(i<1)
        return sum;
    return sum1toNParam(i-1, sum+i);
}
//Factorial 
int facNParam(int i, int fac){
    if(i < 1)
        return fac;
    return facNParam(i-1, fac*i);
}
//Functional
int sum1toNFunc(int i){
    if(i < 1)
        return 0;
    return (i+sum1toNFunc(i-1));
}
int facNFunc(int i){
    if(i<1)
        return 1;
    return (i*facNFunc(i-1));
}

int main(){
    int n = 5, sum = 0;
    cout<<sum1toNParam(n, sum);
    cout<<sum1toNFunc(n);
    cout<<facNParam(n, 1);
    cout<<facNFunc(n);
    return 0;
}