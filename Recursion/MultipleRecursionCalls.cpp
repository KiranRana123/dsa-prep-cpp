#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n<=1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
void test_fibonacci(){
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(10) == 55);
    cout<<"All test cases passed!";
}
int main(){

    test_fibonacci();
    return 0;
}