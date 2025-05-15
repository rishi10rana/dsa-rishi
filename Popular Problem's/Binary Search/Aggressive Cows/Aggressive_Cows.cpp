bool isPossible(vector<int> &stalls,int k,int mid){
    // to track count of cows
    int cowsCount = 1;

    // initial position of cow1
    int lastPos = stalls[0];

    // compare each two stall minimum distance with mid
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastPos>=mid){
            cowsCount++;
            if(cowsCount==k){
                return true; // mid is a possible soln
            }
            lastPos = stalls[i];
        }
    }
    return false; // mid is not a possible soln
}

int aggressiveCows(vector<int> &stalls, int k)
{
    // As we will create a number line to find min distance between each stall to check mid so we need sorted stalls array
    sort(stalls.begin(),stalls.end());
    
    // Create a search space from (0-> to max element in stalls) which could contain our possible answers.
    int start = 0;
    int maxii = -1;
    // Calculate the max element in stalls to make it the "end"
    for(int i=0;i<stalls.size();i++){
        maxii = max(maxii,stalls[i]);
    }
    int end = maxii;
    int mid = start + (end-start)/2;
    int ans = -1; // used this variable to store last close answer

    // Perform binary Search 
    while(start<=end){
        // if mid is possible soln then as we want largest of minimum ans go to right part start = mid + 1
        if(isPossible(stalls,k,mid)){
            ans = mid;
            start = mid + 1;
        }
        // if mid not a possible soln then their exist no minimum distance >= mid so as all distances are less we cant find soln in right 
        // we have to go left  "end = mid - 1"
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}