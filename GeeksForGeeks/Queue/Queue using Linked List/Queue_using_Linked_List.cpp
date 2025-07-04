/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x) // O(1)
{
    QueueNode *node = new QueueNode(x);
    if(front==NULL){
        front = rear = node;
        return;
    }
    rear->next = node;
    rear = node;
}

//Function to pop front element from the queue.
int MyQueue :: pop() // O(1)
{   
    //check queue if empty then cant pop then return -1
    if(front==NULL){
        return -1;
    }
    int value = front->data;
    QueueNode* temp = front;
    front = front->next;
    temp->next = nullptr; // to deal with dangling ptr
    delete temp;
    return value;
}
