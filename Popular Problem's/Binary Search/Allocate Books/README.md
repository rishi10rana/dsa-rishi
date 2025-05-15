### Steps to Solve: 

Question : [Allocate Books](https://www.naukri.com/code360/problems/allocate-books_1089560?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&count=25&search=Allocate&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav&page=1&attempt_status=NOT_ATTEMPTED)

Step 1: Initially create a search space from( 0 ---> (total sum of pages in pages[]) ) within this range only our ans will be present.
		start = 0 ,end = sum , mid = start + (end-start)/2

Step 2: within this search space apply binary search till (start<=end)

Step 3: check if (mid can be a possible solution) -> if yes then store this mid 
		as it cab be a potential answer and make end = mid - 1
		as all values greater than mid will give ans but we want minimum so go left
		
Step 4: check if (mid cannot be a possible solution) ->  then make start = mid + 1
		as all values less than mid will not be able to give answer so will go right to search.
		
#### To check a mid is Possible Soln or Not

Step 1: make a studentCount = 1 ,and pageSum = 0 to store sum of pages for a student

Step 2: traverse on each element of array and 
		if (pageSum + pages[i])<=mid 
		then add that page[i] to pageSum 
		
Step 3: else this student cant allocate this book move to next stduent (studentCount++)
		check here if (studentCount > orginal student no.  OR page[i]>mid) means either we have crossed the no of student or the page[i] is big than mid value
		so this mid cant be soln return false.
		
Step 4: if above condition not runs means their is no problem then update the pageSum = page[i] for new student

Step 5: after whole loop completes and no false is returned then mid is possible soln return true.