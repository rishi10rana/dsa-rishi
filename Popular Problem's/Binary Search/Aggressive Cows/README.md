### Steps to Solve:

Question : [Aggressive Cows](https://www.naukri.com/code360/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM)

Step 1: As to check whether the "mid" i calculated is the answer we will need to create a number line of stalls to find min distance between each stall. 

Step 2: Create a search space from (0-> to max element in stalls) which could contain our possible answers.

Step 3: Calculate the max element in stalls to make it the "end".

Step 4: "ans"used this variable to store last close answer.

Step 5: Perform binary search on search space till (start<=end)

Step 6: Conditons to check:
	1. if (mid is possible answer) then store that possible solution in "ans" and as we need to find largest possible min distance we will search in right of mid ...   start = mid + 1
	2. if mid not a possible soln then their exist no minimum distance >= mid so as all distances are less we cant find soln in right 
        we have to go left  "end = mid - 1"

Step 7: after binary search overs then retur the last close "ans".

#### Function to check mid is possible answer or not

Step 1: Create a cowCount = 1.

Step 2: Create the postion where the cow was placed last  lastPos=stalls[0]

Step 3: compare each two stall minimum distance with mid for this purpose traverse in the stalls[] array 

Step 4: compare (stalls[i] - lastPos >= mid) means cow can be placed nicely so increment cows count and check in between if cowscount = original no. of cows then return true --> means this is a possible soln
	if cowsCount not equals to original means still more cow need to placed so update the lastPos where cow was placed as lastPos=stalls[i]

Step 5: but if above (stalls[i] - lastPos >= mid) fails then return false --> which means this mid cant be the largest minimum distance b/w tohe cows to prevent them from attacking each other.
