#include <bits/stdc++.h>
using namespace std;

void subseqSumK(int i, int sum, vector<int>& ans, int k, vector<int>& arr){
    if(i == arr.size())
    {    
        if(sum == k)
        {
            cout<<"[";
            for(auto i:ans)
                cout<<i<<"  ";
            cout<<"], ";
        }
        return;
    }
    
    ans.push_back(arr[i]);
    subseqSumK(i+1, sum+arr[i], ans, k, arr);
    ans.pop_back();
    subseqSumK(i+1, sum, ans, k, arr);

}

bool subseqSumKOne(int i, int sum, vector<int>& ans, int k, vector<int>& arr){
    if(i == arr.size())
    {    
        if(sum == k)
        {
            cout<<"[";
            for(auto i:ans)
                cout<<i<<"  ";
            cout<<"], ";
            return true;
        }
        return false;
    }
    
    ans.push_back(arr[i]);
    if(subseqSumKOne(i+1, sum+arr[i], ans, k, arr) == true)
        return true;
    ans.pop_back();
    if(subseqSumKOne(i+1, sum, ans, k, arr) == true)
        return true;
    return false;
}

int subseqSumKCount(int i, int sum, int k, vector<int>& arr){
    if(i == arr.size())
    {    
        if(sum == k)
        {
            return 1;
        }
        return 0;
    }
    int l = subseqSumKCount(i+1, sum+arr[i], k, arr);
    int r = subseqSumKCount(i+1, sum, k, arr);
    return l+r;
}

int main() {
    vector<int> ans;
    vector<int> arr = {1,4,6,7,2,3,-10,5,-1};
    vector<int> arr1 = {1,2,1};
    subseqSumK(0,0,ans,16,arr);
    subseqSumKOne(0,0,ans,16,arr);
    cout<<subseqSumKCount(0,0,16,arr);
    return 0;
}
