#include<bits/stdc++.h>
using namespace std;

//print name 5 times
void printNameUtil(int cnt, string& name){
    if(cnt > 5)
        return;
    cout<<name<<endl;
    printNameUtil(cnt+1,name);
}

// print linearly from 1 to n 
void print1toN(int i, int n){
    if(i > n)
        return;  
    cout<<i<<" ";
    print1toN(i+1,n);
}
// print from n to 1 
void printNto1(int i){
    if(i < 1)
        return;  
    cout<<i<<" ";
    printNto1(i-1);
}
// print linearly from 1 to n (backtracking)
void print1toNBT(int i){
    if(i < 1)
        return;  
    print1toNBT(i-1);
    cout<<i<<" ";
}
// print from n to 1(backtracking) 
void printNto1BT(int i, int n){
    if(i > n)
        return;
    printNto1BT(i+1,n);
    cout<<i<<" ";
}

int main(){
    string name = "kiran";
    printNameUtil(0, name);
    print1toN(1,10);
    cout<<endl;
    printNto1(10);
    cout<<endl;
    print1toNBT(10);
    cout<<endl;
    printNto1BT(1,10);
    return 0;
}