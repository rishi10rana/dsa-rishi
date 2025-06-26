class Solution {
  public:
    // Function to delete middle element of a stack.
    // T.C = O(n/2) = O(n)  S.C = O(n) due to recusrion
    void helper(stack<int> &s,int size,int count){
        // base csae stop when reached mid and return back
        if(count == size/2){
            s.pop();
            return;
        }
        
        // before reachingmid at each step remve the top element but before store it
        int store = s.top();
        s.pop();
        // call for next element
        helper(s,size,count+1);
        // when coming back again push the store element
        s.push(store);
    }
    
    
    void deleteMid(stack<int>& s) {
        int count = 0;
        int size = s.size(); //  to preserve size in function as it changes during pop
        helper(s,size,count);
    }
};