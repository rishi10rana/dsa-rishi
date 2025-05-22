#include <bits/stdc++.h> 

void helper(string &str,int start,int end){
	// Base Case
	if(start>end){
		return; // stop
	}

	swap(str[start],str[end]);
	// Recursive Call
	helper(str,start+1,end-1);
}

string reverseString(string str)
{
	// Write your code here.
	helper(str,0,str.length()-1);
	return str;
}