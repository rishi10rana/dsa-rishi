#include <bits/stdc++.h> 

// check karne ke liya kya ye mid answer ho sakta
bool isPossible(vector<int> &pages,int n,int b,int mid){
	int studentCount = 1;
	int pageSum = 0;
	
	for(int i=0;i<n;i++){
		// Possible Solution Case
		if(pageSum+pages[i]<=mid){
			pageSum=pageSum+pages[i];
		}
		else{ // move to next student for allocation of book
			studentCount++;
			if(studentCount>b || pages[i]>mid){
				return false; // means mid ans nahi hoo sakta
			}
			pageSum=pages[i];
		}
	}
	return true; // means mid ans ho sakta hai
}

int allocateBooks(vector<int> &pages, int n, int b)
{
	// Intially we cteated a search space from (0 to total sum of page) becasue our answer will be present
	// within this range only
	int start = 0;
	int sum = 0;
	for(int i=0;i<n;i++){
		sum = sum + pages[i];
	}
	int end = sum;

	int mid = start + (end-start)/2;
	int ans = -1; // This variable is used to store the closest answer till now.
	if(n<b){ // if no of books is less than no of students(ninjas) then we cant allocate atleast one to each
		return ans; // O/P = -1
	}

	// Binary Search on search space
	while(start<=end){
		// if a m id is possible soln then all values graeter than mid will be soln but we want
		// minimum of maximum so hum mid ke piche dundh te. 
		if(isPossible(pages,n,b,mid)){
			ans = mid;	// store last possoble soln
			end = mid - 1;
		}
		// if mid not a possible soln usse kam mei to koii soln nahi hoga to usse aage check karenga
		else{
			start = mid + 1;
		}
		mid = start + (end-start)/2;
	}
	return ans;
}