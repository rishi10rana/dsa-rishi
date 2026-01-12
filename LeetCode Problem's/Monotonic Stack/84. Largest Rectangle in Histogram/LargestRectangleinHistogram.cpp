class Solution {
public:
    // Approach - Monotonic Stack (NSE and PSE)
    // T.C = O(2n) to find NSE and PSE + O(n) to find max area = O(2n + n)
    // it stores the next smaller element index for each ith index
    // S.C = O(n) for extra vectors
    vector<int> getNSE(vector<int>& height){
        int n = height.size();

        vector<int> NSE(n);
        stack<int> st;
        // traverse right to left
        for(int i=n-1;i>=0;i--){
            // means no mext smalle element in stack for current ith
            if(st.empty()){
                NSE[i] = n;
            }
            else{
                // stack mei jo next smaller element hai wo badha element hai 
                while(!st.empty() && height[st.top()] >= height[i]){
                    st.pop();
                }
                // agar stack empty hogaya means current ith index ke liya koii NSE nahi hai
                if(st.empty()){
                    NSE[i] = n;
                }
                else{
                    // stack ka top hi next smaller element hai
                    NSE[i] = st.top();
                }
            }
            // track this current element
            st.push(i);
        }

        return NSE;
    }

    // it stores the previous smaller element index for each ith index
    vector<int> getPSE(vector<int>& height){
        int n = height.size();

        vector<int> PSE(n);
        stack<int> st;
        // traverse left to right
        for(int i=0;i<n;i++){
            // means no previous smaller element in stack for current ith
            if(st.empty()){
                PSE[i] = -1;
            }
            else{
                // stack mei jo previous smaller element hai wo badha element hai 
                while(!st.empty() && height[st.top()] >= height[i]){
                    st.pop();
                }
                // agar stack empty hogaya means current ith index ke liya koii PSE nahi hai
                if(st.empty()){
                    PSE[i] = -1;
                }
                else{
                    // stack ka top hi previous smaller element hai
                    PSE[i] = st.top();
                }
            }
            // track this current element
            st.push(i);
        }

        return PSE;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> NSE = getNSE(heights);
        vector<int> PSE = getPSE(heights);

        // find width possible for each ith index histogram to make a rectangle
        vector<int> width(n);
        for(int i=0;i<n;i++){
            width[i] = NSE[i] - PSE[i] - 1;
        }

        // find max area rectangle that we can get by considering each histogram heights[i]
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int a = heights[i] * width[i];
            maxArea = max(maxArea, a);
        }

        return maxArea;
    }
};