### Approach To Solve - I - Using Pivot Element and Binary Search

- Note store size of array somewhere as it may confuse you.

- first for the given sorted , rotated array using the find pivot index algorithm : find the pivot element (lowest value) index .
- then break the array in two parts using this pivot element and apply binary search individually to parts.

- if(target>=arr[pivot] and target<=arr[n-1]) ---> then apply binary search from (start=pivot) and (end=n-1)  
- else binary search from (start=0) and (end=pivot-1)

- also for target not found binary search will return -1.


### Approach To Solve - II - Using if-else and Binary Search

- we have sorted , rotatead array which is sorted in two parts.
- apply binary search on array till (start<=end)

- Case 1: if arr[mid]==target --> return mid

- Case 2: if  target>=arr[0]  means target is on left part of array 
	
	- Case 1: if target<arr[mid] then make end = mid - 1 
	- Case 2: else if arr[mid]>=arr[0] means mid also lies on left part then start = mid + 1
	- Case 3: else  means mid in right part then make end = mid -1;

- Case 3: else means target is on right part of array 
	
	- Case 1: if target>arr[mid] then make start = mid + 1
	- Case 2: else if arr[mid]>=arr[0] means mid lies on left part then start = mid + 1
	- Case 3: else  means mid in right part then make end = mid -1;
	
- if no target element not found till whole loop terminate return -1.


### Approach To Solve - III - Using Pivot and Binary Search (like I)

- first for the given sorted , rotated array using the find pivot index algorithm : find the pivot element (lowest value) index .

- then break the array in two parts using this pivot element and apply binary search individually to parts.
- but this time we wil use inbuild c++ STL binary_saerch function

-  if(target>=arr[pivot] and target<=arr[n-1]) ---> then apply binary search from (start=pivot) and (end=n-1)  
    here we need iterators so we use (arr.begin+pivot_index)   to (arr.end())
	
-  else binary search from (start=0) and (end=pivot-1)
	so here iteartors are arr.begin() to arr.begin=pivot_index
	
- we can same itearator itr = arr.begin()+pivot_index   
   for both arr[pivot] and arr[pivot-1] as binary_search here is exclusive function it will range from first iteartor to one less.