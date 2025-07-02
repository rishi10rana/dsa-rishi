// Approach 2 : Array Used - ye todha eeasy hai samajh ne mei
class MyCircularQueue {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
        front = -1;
        rear = -1;
    }
    
    // add element in queue T.C = O(1)
    bool enQueue(int value) {
        // chekc karlo kahi queue full too nahi
        if(isFull()){
            return false; // cant add
        }

        // agar first element add kar rahe to first ko bhi updata kardena, rear to update ho hi jayega
        if(front==-1){
            front++;
        }
        // it handle rest all cases
        rear = (rear+1)%size;
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() { // pop  T.C = O(1)
       // chech kahi empty to nahi queue
       if(isEmpty()){
            return false; // cant pop
       }

        // agar sirf ek hi element hai queue mei
        if(front==rear){
            front = rear = -1;
        }
        // baki ye sare case handle karlega
        else{
            front = (front+1)%size;
        }
        return true;
    }   
    
    int Front() { // O(1)
        // check kahi empty to nahi
        if(!isEmpty()){
            return arr[front];
        }
        return -1;
    }
    
    int Rear() { // O(1)
        // check kahi empty to nahi
        if(isEmpty()){
            return -1;;
        }
        return arr[rear];
    }
    
    bool isEmpty() { // O(1)
        if(front==-1){ // means sempty
            return true; 
        }else{
            return false;
        }
    }
    
    bool isFull() { // O(1)
        if((rear+1)%size==front){
            return true; // yes queue full hogayi hai
        }
        return false;
    }
};





// Approach 1 : Array Used - todha ajjeb hai ye tarika
/*
class MyCircularQueue {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
        front = -1;
        rear = -1;
    }
    
    // add element in queue T.C = O(1)
    bool enQueue(int value) {
        // check if  queue is full
        if((rear+1)%size == front){
            return false; // no space cant add
        }

        // adding first element
        if(front==-1){
            front = rear = 0;
        }
        // means rear last tak pahuch gya ab next add karne ke liya wo aage dekhe gaa
        else if((rear==size-1) && front!=0){
            rear = 0; // to maintain cyclic nature
        }
        else{ // means rear bich mei hai kahi , normal case of adding
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() { // pop  T.C = O(1)
        // check karlo kahi queue empty to nahi
        if(front==-1){
            return false;
        }

        // agar ek hi element hai
        arr[front] = -1;
        if(front==rear){ // means ki sirf ek  hi element hai in queue
            front = rear = -1;
        }

        // pop karte karte "front"  wo end tak pahuch gaya
        else if(front==size-1){
            front = 0;
        }

        else{ // noramal case kahi bich mei ho
            front++;
        }
        return true;
    }   
    
    int Front() {
        // check kahi empty to nahi
        if(!isEmpty()){
            return arr[front];
        }
        return -1;
    }
    
    int Rear() {
        // check kahi empty to nahi
        if(!isEmpty()){
            return arr[rear];
        }
        return -1;
    }
    
    bool isEmpty() {
        if(front==-1){ // means sempty
            return true; 
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if((front==0 && rear==size-1) || rear == (front-1)%(size-1)){
            return true; // yes full
        }
        else{
            return false;
        }
    }
};
*/


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */