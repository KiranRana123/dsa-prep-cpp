#include<bits/stdc++.h>
using namespace std;

bool validPalindromeTP(int i, int j, string& str){
    if(i>=j)
        return true;
    
    if(str[i] != str[j])
        return false;
    return validPalindromeTP(i+1, j-1, str);
}

bool validPalindromeSP(int i, string& str){
    if(i>=str.length()/2)
        return true;
    
    if(str[i] != str[str.length()-1-i])
        return false;
    return validPalindromeSP(i+1, str);
}

void test_validPalindromeTP(){
    //palindromes
    string str1= "madam";
    assert(validPalindromeTP(0, str1.length()-1, str1));
    string s2 = "racecar";
    assert(validPalindromeTP(0, s2.length() - 1, s2));

    //non palindromes
    string s3 = "hello";
    assert(!validPalindromeTP(0, s3.length() - 1, s3));

    //edge case1: single character
    string s4 = "a";
    assert(validPalindromeTP(0, s4.length() - 1, s4));

    // edge case2: empty string
    string s5 = "";
    assert(validPalindromeTP(0, s5.length() - 1, s5));

    cout<<"\nAll test cases passed validPalindromeTP!!";
}

void test_validPalindromeSP(){
    //palindromes
    string str1= "madam";
    assert(validPalindromeTP(0, str1.length()-1, str1));
    string s2 = "racecar";
    assert(validPalindromeTP(0, s2.length() - 1, s2));

    //non palindromes
    string s3 = "hello";
    assert(!validPalindromeTP(0, s3.length() - 1, s3));

    //edge case1: single character
    string s4 = "a";
    assert(validPalindromeTP(0, s4.length() - 1, s4));

    // edge case2: empty string
    string s5 = "";
    assert(validPalindromeTP(0, s5.length() - 1, s5));

    cout<<"\nAll test cases passed for validPalindromeSP!!";
}
int main(){
    test_validPalindromeTP();
    test_validPalindromeSP();
    return 0;
}