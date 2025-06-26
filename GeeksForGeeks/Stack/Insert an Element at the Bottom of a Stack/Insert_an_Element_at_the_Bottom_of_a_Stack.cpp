// User function Template for C++

class Solution {
  public:
    // T.C = O(n) S.C = O(n)
    /*
    void helper(stack<int> &st, int count, int size, int x){
        // base case means removed all elements fo stack 
        if(count == size+1){
            st.push(x);
            return;
        }
        // pop elements but before that store them
        int store = st.top();
        st.pop();
        // move to next element to pop
        helper(st,count+1,size,x);
        // after returningback push all of them which we popped
        st.push(store);
    }
    
    stack<int> insertAtBottom(stack<int> st, int x) {
        int count = 1;
        int size = st.size();
        helper(st,count,size,x);
        return st;
    }
    */
    
    // Another way - no need to pass many parameters
    void helper(stack<int> &st,int x){
        // base case means stack became empty
        if(st.empty()){
            st.push(x);
            return;
        }
        // pop elements but before that store them
        int store = st.top();
        st.pop();
        // move to next element to pop
        helper(st,x);
        // after returningback push all of them which we popped
        st.push(store);
    }
    
    stack<int> insertAtBottom(stack<int> st, int x) {
        helper(st,x);
        return st;
    }
};