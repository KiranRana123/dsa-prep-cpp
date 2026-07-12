#include<bits/stdc++.h>
using namespace std;

void printSubseq(int i, vector<int>& arr, vector<int> temp, vector<vector<int>>& ans){
    if(i >= arr.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    printSubseq(i+1, arr, temp, ans);
    temp.pop_back();
    printSubseq(i+1, arr, temp, ans);
}

void test_printSubseq(){
    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {1,2,3,5,23,9,10};
    vector<int> arr3 = {1};
    vector<int> arr4 = {};
    vector<vector<int>> ans, ans2, ans3, ans4;
    vector<int> temp;
    printSubseq(0,arr1,temp,ans);
    printSubseq(0,arr2,temp,ans2);
    printSubseq(0,arr3,temp,ans3);
    printSubseq(0,arr4,temp,ans4);
    assert(ans.size() == pow(2,arr1.size()));
    assert(ans2.size() == pow(2,arr2.size()));
    assert(ans3.size() == pow(2,arr3.size()));
    assert(ans4.size() == pow(2,arr4.size()));
    cout<<"all cases pass!!";
}
int main(){
    test_printSubseq();
    return 0;
}