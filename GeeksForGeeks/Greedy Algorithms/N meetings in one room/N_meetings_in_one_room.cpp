class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    // to compare two pairs
    static bool comp(pair<int,int> p1, pair<int,int> p2){
        // check are they in ascending order based on their end time
        if(p1.second < p2.second){
            return true;
        }
        return false; // means swap them
    }
    
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // add your code here
        
        // stores all activities in form of pair of thier start and end time
        // then sort al the activities on the basis of their end time
        
        vector<pair<int,int>> activity;
        for(int i=0;i<start.size();i++){
            pair<int,int> p = make_pair(start[i],end[i]);
            activity.push_back(p);
        }
        
        sort(activity.begin(), activity.end() ,comp);
        
        // consider first activity
        int count = 1;
        int prevEndTime = activity[0].second;
            
        // check each actitvity from now
        for(int i=1;i<activity.size();i++){
            if(activity[i].first > prevEndTime){
                count++;
                prevEndTime = activity[i].second;
            }
        }
        return count;
    }
};