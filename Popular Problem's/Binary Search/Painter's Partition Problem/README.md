### Steps to Solve: 

Question : [Painters Partition Problem](https://www.naukri.com/code360/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2)

Step 1: Initially create a search space from( 0 ---> (total sum of time in boards[]) ) within this range only our ans will be present.
		start = 0 ,end = sum , mid = start + (end-start)/2

Step 2: within this search space apply binary search till (start<=end)

Step 3: check if (mid can be a possible solution) -> if yes then store this mid 
		as it cab be a potential answer and make end = mid - 1
		as all values greater than mid will give ans but we want minimum so go left
		
Step 4: check if (mid cannot be a possible solution) ->  then make start = mid + 1
		as all values less than mid will not be able to give answer so will go right to search.
		
#### To check a mid is Possible Soln or Not

Step 1: make a paintersCount = 1 ,and totalTime = 0 to store sum of time to paint boards for a painter.

Step 2: traverse on each element of array and 
		if (totalTime + boards[i])<=mid 
		then add that boards[i] to totalTime 
		
Step 3: else this painter cant paint this board move to next painter (paintersCount++)
		check here if (paintersCount > orginal painters no.  OR boards[i]>mid) means either we have crossed the no of painters or the boards[i] is big than mid value
		so this mid cant be soln return false.
		
Step 4: if above condition not runs means their is no problem then update the totalSum = baords[i] for new painter

Step 5: after whole loop completes and no false is returned then mid is possible soln return true.