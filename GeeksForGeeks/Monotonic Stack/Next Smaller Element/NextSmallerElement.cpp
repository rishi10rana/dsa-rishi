class Solution {
  public:
    // Approach - Monotonic Stack
    /// T.C = O(2n)
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> NSE(n);
        
        stack<int> st;
        // traverse right to left
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                // means no next smaller element for current ith index
                NSE[i] = -1;
            }
            else{
                // kahi wo next element in stack badha to nahi
                while(!st.empty() && st.top() >= arr[i]){
                    st.pop();
                }
                
                // agar stack empty hogaya means ko next smaller nahi hai
                if(st.empty()){
                    NSE[i] = -1;
                }
                else{
                    // stack ka top hi next smaller element hai
                    NSE[i] = st.top();
                }
            }
            // track this element
            st.push(arr[i]);
        }
        
        return NSE;
    }
};