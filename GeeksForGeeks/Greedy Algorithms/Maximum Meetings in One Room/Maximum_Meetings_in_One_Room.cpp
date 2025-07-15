// User function Template for C++
// created a struct to store data of 1 meeting
struct meeting{
    int startTime;
    int finishTime;
    int meetingNo;
};

class Solution {
  public:
  // T.C = O(nlogn) S.C = O(n)
    static bool comp(meeting m1 , meeting m2){
        return m1.finishTime < m2.finishTime;
    }
  
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        // group all the meetings in a single vector to acess their data using index
        vector<meeting> meetings(N);
        for(int i=0;i<N;i++){;
            meetings[i].startTime = S[i];
            meetings[i].finishTime = F[i];
            meetings[i].meetingNo = i+1;
        }
        
        // sort each meeting based on its finsish time
        sort(meetings.begin(),meetings.end(),comp);
        
        vector<int> result;
        
        // traveerse all meeting from starting
        int prevFinishTime = -1;
        
        for(int i=0;i<N;i++){
            if(meetings[i].startTime > prevFinishTime){
                result.push_back(meetings[i].meetingNo); // activity no
                prevFinishTime = meetings[i].finishTime;
            }
        }
        // give the activity nos in sorted form
        sort(result.begin(),result.end());
        
        return result;
    }
};