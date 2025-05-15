// check karne ke liya kya ye mid answer ho sakta
bool isPossible(vector<int> &boards,int n,int k,int mid){
    int painterCount = 1;
    int totalTime = 0;
    for(int i=0;i<n;i++){
        // Possible Solution Case
        if(totalTime+boards[i]<=mid){
            totalTime = totalTime + boards[i];
        }
        else{ // move to next painter for allocation of board
            painterCount++;
            if(painterCount > k || boards[i] > mid){
                return false; // means mid ans nahi hoo sakta
            }
            totalTime = boards[i];
        }
    }
    return true; // means mid ans ho sakta hai
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    // Initially create a search space from (0 --> total sum of boards time to paint) within this range ans will be their
    int start = 0;
    int sum = 0;
    int n = boards.size();
    for(int i=0;i<n;i++){
        sum = sum + boards[i];
    }
    int end = sum;
    int mid = start + (end-start)/2;

    int ans = -1; // This variable is used to store the closest answer till now

    // Binary Search on search space
    while(start<=end){ 
        // if a m id is possible soln then all values greater than mid will be soln but we want
		// minimum of maximum so hum mid ke piche dundh te. 
        if(isPossible(boards,n,k,mid)){
            ans = mid; // store last possible soln
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