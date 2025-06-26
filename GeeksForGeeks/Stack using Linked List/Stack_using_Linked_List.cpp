class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) { // O(1)
        // creata a node
        StackNode* node = new StackNode(x);
        node->next = top; // store previous node which was top
        top = node; //update the top
    }

    int pop() { // O(1)
        // check for stack empty
        if(top==NULL){
            return -1;
        }
        // means element their we can remove
        int ans = top->data;
        StackNode* temp = top; // store top before
        top = top->next; // move top to previous node
        temp->next = NULL;
        delete temp;
        return ans;
    }

    MyStack() { top = NULL; }
};