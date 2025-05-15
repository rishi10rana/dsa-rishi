#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	// Write your code here.
	string temp = "";

	// Traver on individual characters
	for(int i=0;i<str.length();i++){
		// if space instead of it add @40
		if(str[i]==' '){
			temp.push_back('@');
			temp.push_back('4');
			temp.push_back('0');
		}
		// if a letter add it simply
		else{
			temp.push_back(str[i]);
		}
	}

	// final string
	return temp;
}


// In-place Solution of Problem
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	// Write your code here.
	// string with which space is replaced
	string str2 = "@40";

	for(int i=0;i<str.length();i++){
		// if encountered a space replace it with '@40'
		if(str[i]==' '){
			// use replace function of string
			str.replace(i,1,str2);
		}
		else{
			continue;
		}
	}

	// final answer
	return str;
}