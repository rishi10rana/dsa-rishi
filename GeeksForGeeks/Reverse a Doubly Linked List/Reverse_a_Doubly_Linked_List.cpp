/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    // Approach - Iterative Approach T.C = O(n)
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode* prevNode = NULL;
        DLLNode* currentNode = head;
        DLLNode* forwardNode = NULL;
        
        while(currentNode != NULL){
            forwardNode = currentNode->next;
            currentNode->next = prevNode;
            currentNode->prev = forwardNode;
            prevNode = currentNode;
            currentNode = forwardNode;
        }
        return prevNode;
    }
};