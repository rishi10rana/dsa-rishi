class twoStacks {
  public:
    // Properties
    int* arr;
    int top1;
    int top2;
    int size;
    
    // Constructor
    twoStacks() {
        this->size = 1000;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    // Function to push an integer into the stack1.
    void push1(int x) { // O(1)
        if(top2- top1 > 1){ // check if space their
            top1++;
            arr[top1] = x;
        }
        else{ // means no space
            return;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) { // O(1)
        if(top2 - top1 > 1){ // chec if space their
            top2--;
            arr[top2] = x;
        }
        else{ // no space
            return;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() { // O(1)
        if(top1>=0){ // means elements are their
            int ans = arr[top1];
            top1--;
            return ans;
        }else{ // means stack1 is empty
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() { // O(1)
        if(top2<size){ // means element are their
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{ // means stack2 is empty
            return -1;
        }
    }   
};