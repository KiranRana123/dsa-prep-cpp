#include <bits/stdc++.h>
using namespace std;

void merge(int low, int high, int mid, vector<int>& arr){
    vector<int> ans;
    int left = low;
    int right = mid+1;
    while(left <= mid && right<= high){
        if(arr[left] <= arr[right])
        {   ans.push_back(arr[left]);
            left++;
        }else
         {   ans.push_back(arr[right]);
            right++;}
    }
    while(left <= mid)
    {
        ans.push_back(arr[left]);
        left++;
    }
    while(right<= high){
        ans.push_back(arr[right]);
        right++;
    }
    for(int i = low; i<=high; i++)
        arr[i] = ans[i-low];
}
void mergeSort(int low, int high, vector<int>& arr){
    if(low == high)
        return;
    int mid =  ((high - low)/2) + low;
    mergeSort(low, mid, arr);
    mergeSort(mid+1, high,arr);
    merge(low, high, mid, arr);
}

void testRandomRuns() {
    srand(time(nullptr));

    for (int t = 0; t < 1000; t++) {
        int n = rand() % 100;
        vector<int> a(n);

        for (int &x : a)
            x = rand() % 1000 - 500;

        vector<int> expected = a;
        sort(expected.begin(), expected.end());

        if (!a.empty())
            mergeSort(0, a.size() - 1, a);

        assert(a == expected);
    }
    cout << "Random tests passed!\n";
}

void runTest(vector<int> input, vector<int> expected) {
    if (!input.empty())
        mergeSort(0, input.size() - 1, input);
    assert(input == expected);
}

void test_mergeSort() {
    runTest({3,2,4,1,3},
            {1,2,3,3,4});

    runTest({3,1,2,4,1,5,2,6,4},
            {1,1,2,2,3,4,4,5,6});

    runTest({},
            {});

    runTest({1},
            {1});

    runTest({11,8},
            {8,11});

    runTest({5,4,3,2,1},
            {1,2,3,4,5});

    runTest({1,2,3,4,5},
            {1,2,3,4,5});

    runTest({7,7,7,7},
            {7,7,7,7});

    runTest({-2,5,-10,0,3},
            {-10,-2,0,3,5});

    cout << "All test cases passed!\n";
}

int main() {
    testRandomRuns();
    test_mergeSort();
    return 0;
}