/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // T.C = O(n)
    ListNode* deleteMiddle(ListNode* head) {
        // first count total no of nodes
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }

        if(size==1){ // only 1 element
            head = nullptr;
            return head;
        }

        ListNode* current = head;
        ListNode* prev = NULL;
        int count = 0;
        // middle element = size/2
        // place the current pointer at the middle and the previous just behind it
        while(count < floor(size/2)){
            prev = current;
            current = current -> next;
            count++;
        }
        prev->next = current->next;
        current->next = NULL; // to prevent dangling pointer
        delete current; // delete the node
        return head;
    }
};