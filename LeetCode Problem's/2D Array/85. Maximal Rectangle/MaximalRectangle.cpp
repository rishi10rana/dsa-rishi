class Solution {
public:
    vector<int> getNSR(vector<int>& height){
        // a function which stores next smaller element right (index) for each height[i];
        int n = height.size();

        vector<int> NSR(n);
        stack<int> st; // will use a stack to track small elements index on right (traverse R -> L)
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                NSR[i] = n; // index out of bound daaldo
            }
            else{
                // agra st mei sab bade mil rahe to pop them
                while(!st.empty() && height[st.top()] >= height[i]){
                    st.pop();
                }

                // agar st empty hogaya pura
                if(st.empty()){
                    NSR[i] = n;
                }
                else{
                    // means st ka top NSR element hai moforre current height[i]
                    NSR[i] = st.top();
                }      
            }
            // means is 'i'th element ke liya NSR mil gaya so st mei daaldo isse to track it
            st.push(i); 
        }

        return NSR;
    }

    vector<int> getNSL(vector<int>& height){
        // a function which stores next smaller element left (index) for each height[i];
        int n = height.size();

        vector<int> NSL(n);
        stack<int> st; // will use a stack to track small elements index on right (traverse L -> R)
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                NSL[i] = -1; // index out of bound daaldo
            }
            else{
                // agra st mei sab bade mil rahe to pop them
                while(!st.empty() && height[st.top()] >= height[i]){
                    st.pop();
                }

                // agar st empty hogaya pura
                if(st.empty()){
                    NSL[i] = -1;
                }
                else{
                    // means st ka top()  NSL element hai for current height[i]
                    NSL[i] = st.top();
                }      
            }
            // means is 'i'th element ke liya NSL mil gaya so st mei daaldo isse to track it
            st.push(i); 
        }

        return NSL;
    }

    int findMaxArea(vector<int>& height){
        // height - height[i]
        // width - width[i] = NSR[i] - NSL[i] - 1;
        int n = height.size();

        vector<int> NSR = getNSR(height); // next smaller right array
        vector<int> NSL = getNSL(height);  // next smaller left array

        vector<int> width(n); // to store kitna width ka rectangle ban sakte for each height[i]
    
        for(int i=0;i<n;i++){
            width[i]  = NSR[i] - NSL[i] - 1;
        }

        // find area of reactangle to ban para
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int a = height[i] * width[i];
            maxArea = max(maxArea, a);
        }

        // max rea reactangle jo ban paa raha by considering given heights
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // vector to store height of considered rows
        vector<int> height(n);
        
        // first consider karo sirf 0th row
        for(int i=0;i<n;i++){
            height[i] = (matrix[0][i] == '1'? 1 : 0); // agar 1 hai to 1 daalo agar 0 hai to 0 daalo
        }

        // will first find the max area rectangle possible for 0th row
        int maxArea = findMaxArea(height);

        // now one by one consider add other rows in height 
        // to check ki agar iss row ko bhi consider karle to max heigth kitni mil payegi
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col] == '0'){ // means 0 height ki building banegi
                    height[col] = 0;
                }
                else{ // '1' means ye height building ki height mei contribute karega
                    height[col] += 1;
                }
            }

            // is row ko bhi consider karke konsa max area ka reactangle mil payega
            maxArea = max(maxArea, findMaxArea(height));
        }

        return maxArea;
    }
};