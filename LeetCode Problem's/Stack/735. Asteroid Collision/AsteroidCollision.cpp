class Solution {
public:
    // Stack
    // T.C = O(N) , S.C = O(N)
    /*
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int> st;


        for(auto &a: asteroids){
            // agar collision ho raha

            while(!st.empty() && st.top()>0 && a<0){
                int sum = st.top() + a;
                
                if(sum<0){ // maltab positive wale ko destory kardiya
                    st.pop();
                }
                else if(sum>0){ // maltab negative wale ko destory kardo
                    a = 0;
                    // break;
                }
                else{ // sum = 0
                    // dono ko destroy kardo
                    st.pop();
                    a = 0;
                }
            }

            if(a!=0){
                st.push(a);
            }
        }

        vector<int> result(st.size());
        for(int i=st.size()-1;i>=0;i--){
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
    */


    // Stack using just vector
    // T.C = O(N) , S.C = O(1)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        vector<int> st;


        for(auto &a: asteroids){
            // agar collision ho raha

            while(!st.empty() && st.back()>0 && a<0){
                int sum = st.back() + a;
                
                if(sum<0){ // maltab positive wale ko destory kardiya
                    st.pop_back();
                }
                else if(sum>0){ // maltab negative wale ko destory kardo
                    a = 0;
                    // break;
                }
                else{ // sum = 0
                    // dono ko destroy kardo
                    st.pop_back();
                    a = 0;
                }
            }

            if(a!=0){
                st.push_back(a);
            }
        }

        return st;
    }
};