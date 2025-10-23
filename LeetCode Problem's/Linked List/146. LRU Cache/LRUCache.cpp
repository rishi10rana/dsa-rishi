class CacheNode{
    public:
    int key, value;
    CacheNode* prev;
    CacheNode* next;
    CacheNode(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Concept Used
// Doubly Linked List
// Map (Hashing)
// Least Recently used Cache

// as used unordered_map thats why for map operation O(1) otherwise for ordered_map may take log(n)

class LRUCache {
public:
    unordered_map<int, CacheNode*> mpp;
    int capacity;
    // dummy head and tail
    CacheNode* head = new CacheNode(-1, -1);
    CacheNode* tail = new CacheNode(-1, -1);

    // O(1)
    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear(); // removes all elements from container
        head->next = tail;
        tail->prev = head;
    }

    // O(1)
    void deleteNode(CacheNode* node){
        CacheNode* prevNode = node->prev;
        CacheNode* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    // O(1)
    void insertAfterHead(CacheNode* node){
        CacheNode* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
    }

    // O(1)
    int get(int key) {
        // not present in map
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        // means present the map so we can get the value
        CacheNode* node = mpp[key]; 

        // as we used the "node" so make it most recent by deleting it and placing same node at front after head
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }
    
    // O(1)
    void put(int key, int value) {
        // means already in map so update the value of node and make it most recent used
        if(mpp.find(key) != mpp.end()){
            CacheNode* node = mpp[key];
            node->value = value;

            // delete the node and add it in front
            deleteNode(node);
            insertAfterHead(node);
        }
        else{ // means not in map need to be added
            // chechk if capacity  filled remove the least recent used cache
            if(mpp.size() == this->capacity){
                // delete from last
                CacheNode* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            // add the new node
            CacheNode* newNode = new CacheNode(key,value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */