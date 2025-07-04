class MyStack {
public:
    // Optimzed Approach - using 1 queue
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) { // O(n)
        // each time we push element in queue reverse the queue
        q.push(x);
        int size = q.size();
        for(int i=0;i,i<size-1;i++){
            int value = q.front();
            q.pop();
            q.push(value);
        }
    }
    
    int pop() { // O(1)
        // now as in queue everytime front is having  top (last added element)
        int value = q.front();
        q.pop();
        return value;
    }
    
    int top() { // O(1)
        // now as in queue everytime front is having  top (last added element)
        return q.front();
    }
    
    bool empty() { // O(1)
        if(q.empty()){
            return true;
        }
        return false;
    }
    

    // Approach  - using 2 queue T.C = O(n) S.C = O(n)
    /*
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }

    void swap(){
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    void push(int x) { 
        // phela agar koii bhi element aaye to use q2 me daalna
        q2.push(x);

        // fhir agar q1 mei phela se element hai to unnhe ek ek karke q2 mei daaldo
        // this make sures at each every element we add in queue it becomes top
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // then this function moves all element q2 to q1 again
        swap();
    }
    
    // In this way q1 will have top() element at front
    int pop() { 
        int value = q1.front();
        q1.pop();
        return value;
    }
    
    int top() { 
        return q1.front();
    }
    
    bool empty() { 
        return q1.empty();
    }
    */
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */