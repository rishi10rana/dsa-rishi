// User function Template for C++

class Solution {
  public:
    // Approach - T.C = O(n^2) S.C = O(n^2)
    
    void insertAtBottom(stack<int> &St,int top){
        // base case
        if(St.empty()){
            St.push(top);
            return;
        }
        // but it elements are thier first pop all then insert
        int temp = St.top();
        St.pop();
        insertAtBottom(St,top);
        St.push(temp);
    }
  
    void Reverse(stack<int> &St) {
        // base case to sotp hen stack becomes empty and return back
        if(St.empty()){
            return;
        }
        
        // before popping store the element
        int top = St.top();
        St.pop();
        
        // call the function to pop next element
        Reverse(St);
        // When coming back insert each element at bottom 
        insertAtBottom(St,top);
    }
};