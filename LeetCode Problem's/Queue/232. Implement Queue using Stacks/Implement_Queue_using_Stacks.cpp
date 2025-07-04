class MyQueue {
public:
    // Implement using 2 stack
    stack<int> inStack; // for doing push opeartion
    stack<int> outStack; // for doing pop opeartion
    MyQueue() {
    }

    void push(int x) {
        // for push use inStac
        inStack.push(x);
    }

    void shiftElements(){ // O(1)
     // shift from instack to outstack
        if(outStack.empty()){ // do only if outstack empty
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
    
    int pop() { // O(n)
        // for doing pop opeartion foirst shift all elementes from insatck to outstack
        shiftElements();
        // now do pop on outstack
        int value = outStack.top();
        outStack.pop();
        return value;
    }

    
    int peek() { // O(n)
        // same shift first then get top
        shiftElements();
        return outStack.top();
    }
    
    bool empty() {
        // check emepty for both stack
        if(inStack.empty() && outStack.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */