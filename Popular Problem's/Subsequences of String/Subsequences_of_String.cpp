#include <bits/stdc++.h>

void helper(string str,string output,int index,vector<string> &ans){
	// Base Case
	if(index>=str.length()){
		// add a condition here to add the subsequence to answer only if it is non-empty
		if(!(output.empty())){
			ans.push_back(output);
		}
		return; // stop here
	}

	// Exclude a character
	helper(str,output,index+1,ans);

	// Include a character
	char ch = str.at(index);
	output.push_back(ch);
	helper(str,output,index+1,ans);
}

vector<string> subsequences(string str){
	// Write your code here
	vector<string> ans; // To store collection of all subsequences
	string output= ""; // to store a subsequence formed
	int index = 0; // // pointer to maintain current character
	helper(str,output,index,ans);
	return ans;
}
