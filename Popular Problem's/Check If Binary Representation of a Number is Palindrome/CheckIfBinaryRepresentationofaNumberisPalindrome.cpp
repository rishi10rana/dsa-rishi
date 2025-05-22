#include <bits/stdc++.h> 
string numberToBinary(long long N){
    // Base Case
    if(N==0){
        return ""; // return an empty string to store answer
    }
    string str = numberToBinary(N>>1);
    int digit = N&1; // to get the binary digit
    return str + to_string(digit);
}

bool helper(string str,int start,int end){
    // Base Case
    if(start>end){
        return true; // yes pallindrome
    }
    if(str[start]!=str[end]){
        return false; // not pallindrome
    }
    else{
        return helper(str,start+1,end-1);
    }
}

bool checkPalindrome(long long N)
{
    // Write your code here.
    string str = numberToBinary(N); // to convert number input to a binary string
    return helper(str,0,str.length()-1);  // to check whether binary string is pallindrome or not

}