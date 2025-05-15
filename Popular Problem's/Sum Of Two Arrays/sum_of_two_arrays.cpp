#include <bits/stdc++.h> 

// Simple function to reverse the order of the elements in an array
vector<int> reverse(vector<int> arr){
	int start = 0;
	int end = arr.size()-1;

	while(start<=end){
		swap(arr[start],arr[end]);
		start++; 
		end--;
	}

	return arr;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Define a vector to store result
	// Define 2 pointers i and j poinitng to ending indes of "a" and "b" respectively
	vector<int> result;
	int i=n-1;
	int j=m-1;

	// To store any carry initally is 0
	int carry = 0;

	// Loop to add elemenets till it is present in both arrays
	while(i>=0 && j>=0){
		int value1 = a[i];
		int value2 = b[j];
		int sum = value1 + value2 + carry;
		carry = sum/10;
		sum = sum%10;
		result.push_back(sum);
		i--;
		j--;
	}
	
	// To take elements of only array "a" which are left also carry currently 
	while(i>=0){
		int sum = a[i] + carry;
		carry = sum/10;
		sum = sum%10;
		result.push_back(sum);
		i--;
	}

	// To take elements of only array "b" which are left also carry currently 
	while(j>=0){
		int sum = b[j] + carry;
		carry = sum/10;
		sum = sum%10;
		result.push_back(sum);
		j--;
	}

	// final loop to include an remaining carry values
	while(carry!=0){
		int sum = carry;
		carry = sum/10;
		sum = sum%10;
		result.push_back(sum);
	}

	// final answer comes but it is reverse order so we need to rever the order
	return reverse(result);
}