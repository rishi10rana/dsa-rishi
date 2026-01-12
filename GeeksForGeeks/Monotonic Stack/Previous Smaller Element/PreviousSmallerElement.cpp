class Solution {
  public:
    // Approach - Monotonic Stack
    // T.C = O(2n)
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> PSE(n);
        
        stack<int> st;
        // traverse left to right
        for(int i=0;i<n;i++){
            if(st.empty()){
                // means no previous smaller element for current ith index
                PSE[i] = -1;
            }
            else{
                // kahi wo previous smaller element in stack badha to nahi
                while(!st.empty() && st.top() >= arr[i]){
                    st.pop();
                }
                
                // agar stack empty hogaya means ko previous smaller nahi hai
                // for current ith index
                if(st.empty()){
                    PSE[i] = -1;
                }
                else{
                    // stack ka top hi previous smaller element hai
                    PSE[i] = st.top();
                }
            }
            // track this element
            st.push(arr[i]);
        }
        
        return PSE;
    }
};