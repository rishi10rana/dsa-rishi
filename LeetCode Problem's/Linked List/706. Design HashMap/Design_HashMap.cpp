// class for defining node structure
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node(int key, int value){
        this->key = key;
        this->val = value;
        this->next = NULL;
    }
};

// This weil create a hashmap which will use concept bucket
class MyHashMap {
    Node **buckets;
    int size;

public:
    MyHashMap() {
        this->size = 1000; // no of buckets
        buckets = new Node*[size](); // () -> initializes all the pointer of this array to nullptr
    }

    // the hash will hel us to identify at which index of bucket we would go to add key-value pair , or search or get key-value pair - helps for fast access
    int hash(int key){
        return key%size;
    }

    void put(int key, int value) { // O(n)
        // find index to determine wt whch buckets to add
        int index = hash(key);

        // if no node their 
        if(buckets[index]==NULL){
            buckets[index] = new Node(key, value);
            return;
        }
        // traverse the L.L
        Node* current = buckets[index];
        while(current!=NULL){
            if(current->key==key){ // means key-value already their so update it
                current->val = value;
                return;
            }

            // if encountered end node then add after it
            if(current->next==NULL){
                current->next = new Node(key, value);
                return;
            }
            current = current->next;
        }
    }
    
    int get(int key) { // O(n)
        // find the index 
        int index = hash(key);
        Node* current = buckets[index];

        while(current!=NULL){
            if(current->key==key){ // means key found
                return current->val;
            }
            current = current->next;
        }
        return -1; // means not found key
    }
    
    void remove(int key) { // O(n)
        // find at which index of bucket we will find keyt
        int index = hash(key);
        Node* current = buckets[index];

        // consder if no node (no key) exists in that bucket
        if(current==nullptr){
            return;
        }

        // if deleting first node
        if(current->key == key){
            Node* temp = current;
            buckets[index] = current->next;
            current = current->next;
            temp->next = nullptr;
            delete temp;
            return;
        }

        // traverse the LL 
        while(current->next!=NULL){
            if(current->next->key==key){ // means key found
                Node* temp = current->next;
                current->next = current->next->next;
                temp->next = NULL;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */