// Approach - 1 : Singly Linked List
/*
class Node{
    public:
    int val;
    Node* next;

    // Constructor
    Node(int value){
        this->val = value;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    int size;

    MyLinkedList(){
        this->size = 0;
        this->head = NULL;
    }
    // T.C = O(N)
    int get(int index) {
        if(index<0 || index>=size){
            return -1;
        }
        Node* temp = head;
        int count = 0;
        while(count<index){
            temp = temp->next;
            count++;
        }
        return temp->val;
    }
    // T.C = O(1);
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        this->size++;
        if(head==NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    // T.C = O(N)
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        this->size++;
        if(head==NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }       
    }
    // T.C = O(N)
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        else if(index==0){
            addAtHead(val);
        }
        else if(index==size){
            addAtTail(val);
        }
        else{
            Node* newNode = new Node(val);
            Node* temp = head;
            int count = 0;
            while(count<index-1){
                temp = temp->next;
                count++;
            }

            newNode->next = temp->next;
            temp->next = newNode;
            this->size++;
        }
    }
    // T.C = O(N)
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        else if(head==NULL){
            return;
        }
        else if(index==0){
            Node* currentNode = head;
            head = head->next;
            this->size--;
            currentNode->next = NULL;
            delete currentNode;
        }
        else{
            Node* prevNode = NULL;
            Node* currentNode = head;
            int count = 0;
            while(count<index){
                prevNode = currentNode;
                currentNode = currentNode->next;
                count++;
            }

            prevNode->next = currentNode->next;
            currentNode->next = NULL;
            this->size--;
            delete currentNode;
        }
    }
};
*/

// Approach 2 - Doubly Linked List
class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    // Constructor
    Node(int value){
        this->val = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    // T.C = O(N)
    int get(int index) {
        if(index<0 || index>=size){
            return -1;
        }
        Node *temp = head;
        int count = 0;
        while(count<index){
            temp = temp->next;
            count++;
        }
        return temp->val;
    }
    // T.C = O(1)
    void addAtHead(int val) {
       Node* newNode = new Node(val);
       this->size++;
       if(head==NULL){
        this->head = newNode;
        this->tail = newNode; 
       }
       else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
       }
    }
    // T.C = O(N)
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        this->size++;
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            this->tail = newNode;
        }
    }
    // T.C = O(N)
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        else if(index==0){
            addAtHead(val);
            return;
        }
        else if(index==size){
            addAtTail(val);
            return;
        }
        else{
            Node* newNode = new Node(val);
            Node *temp = head;
            int count = 0;
            while(count<index-1){
                temp = temp->next;
                count++;
            }

            newNode->next = temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
            this->size++;
        }
    }
    // T.C = O(N)
    void deleteAtIndex(int index) {
       if(index<0 || index>=size){
            return;
       }
       else if(index==0){
            Node* temp = head;
            head = temp->next;
            if(temp->next!=NULL){
                temp->next->prev = NULL;
            }
            temp->next = NULL;
            this->size--;
            delete temp;
       }
       else{
        Node* currentNode = head;
        Node* prevNode = NULL;
        int count = 0;
        while(count < index){
            prevNode = currentNode;
            currentNode = currentNode->next;
            count++;
        }
        if(currentNode->next==NULL){
            tail = prevNode;
        }

        prevNode->next = currentNode->next;
        if(currentNode->next!=NULL){
            currentNode->next->prev = prevNode;
        }
        currentNode->next = NULL;
        currentNode->prev = NULL;
        this->size--;
        delete currentNode;
       }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */