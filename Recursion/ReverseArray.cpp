#include<bits/stdc++.h>
using namespace std;


void revArrayRec(int i, vector<int>& arr){
    if(i < 0)
        return;
    cout<<arr[i]<<" ";   
    revArrayRec(i-1, arr);  
}

void revArrayBack(int i, vector<int>& arr){
    if(i == arr.size())
        return;
    revArrayBack(i+1, arr);  
    cout<<arr[i]<<" ";   
}

void revArrayParam(int i, vector<int>& arr, vector<int>& newarr){
    if(i < 0)
        return;
    newarr.push_back(arr[i]);    
    revArrayParam(i-1, arr, newarr);  
}

void revArrayTwoVar(int i, int j, vector<int>& arr){
    if(i >= j)
        return;
    swap(arr[i],arr[j]);
    revArrayTwoVar(i+1, j-1, arr);  
}

void revArrayInp(int i, vector<int>& arr){
    if(i > arr.size()/2)
        return;
    swap(arr[arr.size()-1-i],arr[i]);
    revArrayInp(i+1, arr);  
}

int main(){
    vector<int> array = {1,2,3,4,10,6};
    vector<int> array2 = {1,2,3,4,10,6};
    vector<int> array3 = {1,2,3,4,10,6};

    vector<int> newarr;
    
    cout<<"revArrayRec : ";
    revArrayRec(array.size()-1, array);

    cout<<"\nrevArrayBack : ";
    revArrayBack(0, array);
    
    cout<<"\nrevArrayParam : ";
    revArrayParam(array.size()-1, array, newarr);
    for(auto i:newarr)
        cout<<i<<" ";

    cout<<"\nrevArrayInp : ";
    revArrayInp(0,array2);
    for(auto i:array2)
        cout<<i<<" ";

    cout<<"\nrevArrayTwoVar : ";
    revArrayTwoVar(0,array3.size()-1, array3);
    for(auto i:array3)
        cout<<i<<" ";

    return 0;
}
