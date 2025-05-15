// Actual Accepted Code
#include <bits/stdc++.h> 
#include <ctype.h>

char toLower(char ch){
    if(ch >='a' && ch<='z' || ch >='0' && ch<='9'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.length()-1;

    while(start<=end){
        // is alnum() func check a char is alphanumeric or not if yes returns any non-zer number(true) if not returns zero(false).
        while(start<end && isalnum(s[start])==0){
            start++;
        }
        while(start<end && isalnum(s[end])==0){
            end--;
        }
        if(toLower(s[start])!=toLower(s[end])){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}


// Approach 2
#include <bits/stdc++.h> 

// Function to convert Upper--> Lower and ignore already lower character and ignore numbers
char upperToLowerCase(char ch){
    if(ch >='a' && ch <='z'){
        return ch; // already lower
    }
    else if(ch >= '0' && ch <= '9'){
        return ch; // its a number just return it
    }
    else{ // if not lower convert it
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s)
{
    // Use 2-Pointer
    int start = 0;
    int end = s.length()-1;

    while(start<=end){
        if((s[start]>=33 && s[start]<=47) ||  (s[start]>=58 && s[start]<=64) || s[start]==' '){
            start++; // ignore any special character or space
        }
        else if((s[end]>=33 && s[end]<=47) ||  (s[end]>=58 && s[end]<=64) || s[end]==' '){
            end--; // ignore any special character or space
        }
        else if(upperToLowerCase(s[start])!=upperToLowerCase(s[end])){
            return false; // if compared element not equal means not pallindrome
        }
        else{
            start++;
            end--;
        }
    }
    return true; // otherwise a pallindrome
}