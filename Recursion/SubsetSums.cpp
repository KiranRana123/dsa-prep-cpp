/*
Given an array nums of n integers. Return array of sum of all subsets of the array nums.

Output can be returned in any order.

Example 1

Input : nums = [2, 3]

Output : [0, 2, 3, 5]

Explanation :

When no elements is taken then Sum = 0.

When only 2 is taken then Sum = 2.

When only 3 is taken then Sum = 3.

When element 2 and 3 are taken then sum = 2+3 = 5.

Example 2

Input : nums = [5, 2, 1]

Output : [0, 1, 2, 3, 5, 6, 7, 8]

Explanation :

When no elements is taken then Sum = 0.

When only 5 is taken then Sum = 5.

When only 2 is taken then Sum = 2.

When only 1 is taken then Sum = 1.

When element 2 and 1 are taken then sum = 2+1 = 3.
*/

#include <bits/stdc++.h>
using namespace std;

void subsetSum(int i, vector<int>& nums, int sum, vector<int>& ans)
{
    if(i == nums.size())
    {   ans.push_back(sum); 
        return;
    }
    subsetSum(i+1, nums, sum + nums[i], ans);
    subsetSum(i+1, nums, sum, ans);
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    int sum = 0;
    subsetSum(0, nums, sum, ans);
    sort(ans.begin(), ans.end());
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}