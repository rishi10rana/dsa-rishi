// Apparoach 1 - Used Array - Todhi ajeeb way to solve
class MyCircularDeque {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) { // O(1)
        // check karlo full to nahi
        if(isFull()){
            return false; // cant add
        }
        
        // adding first element
        if(front==-1){
            front= rear = 0;
        }
        // agar front wo add karte karte strating tak pahcuh gaya to usse picche bhej do
        else if(front==0 && rear!=size-1){
            front=size-1;
        }
        else{ // normal case
            front--;
        }
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {  // O(1)
        // check karlo full to nahi
        if(isFull()){
            return false; // cant add
        }

        // adding first element
        if(front==-1){
            front = rear = 0;
        }
        // add karte karte rear last tak pahuch gaya to usse ab aage bhej do
        else if(rear==size-1 && front!=0){
            rear = 0;
        }
        else{ // normal case
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {  // O(1)
        // check karlo khali to nahi
        if(isEmpty()){
            return false; // cant pop
        }

        // ek hi element hai bus
        arr[front] = -1;
        if(front==rear){
            front = rear = -1;
        }
        // pop karte karte front last tak pahcu hagaya to usse wapis aage le aao
        else if(front==size-1){
            front=0;
        }
        else{ // normal case
            front++;
        }
        return true;
    }
    
    bool deleteLast() {  // O(1)
        // check karlo kahi empty to nahi
        if(isEmpty()){
            return false; // cant delete
        }

        // ek hi element hai bus
        arr[rear] = -1;
        if(front==rear){
            front = rear = -1;
        }
        // pop karte karte rear wo aage tak pahuch gaya to usse wapis picche le aao
        else if(rear==0){
            rear = size -1;
        }
        else{ // normal case
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1){
            return true; // yes empty
        }
        return false;
    }
    
    bool isFull() {
        if((rear+1)%size==front){
            return true; // yes full
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */