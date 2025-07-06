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
    // this wll reverse the linked list
    ListNode* reverseLL(ListNode* head){
        // if no node or single node
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* prevNode = NULL; 
        ListNode* currentNode = head; 
        ListNode* nextNode = NULL; 
        while(currentNode!=NULL){
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode; // which will become head
    }

    // T.C = O(n)  S.C = O(1)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // check karlo for empty list or onoy 1 node
        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* prevNode = NULL; // to track the node just behind from where the reverse start
        ListNode* currentNode = head; 
        ListNode* nextNode = NULL; // to tarck the node just after the place everse end

        int count = 1;
        while(count < left){
            prevNode = currentNode;
            currentNode = currentNode->next;
            count++;
        }
        ListNode* start = currentNode; // from here the reverse start

        while(count!=right){
            currentNode = currentNode->next;
            count++;
        }

        nextNode = currentNode->next;
        currentNode->next = NULL; // make it null so that now we can rever the islolated part
        
        ListNode* newHead = reverseLL(start); // will rerturen the new head after reverse

        // connect the first part
        if(prevNode!=NULL){
            prevNode->next = newHead;
        }
        
        start->next = nextNode; // connect last part
        // final node to return
        if(left==1){ // edge case : means reversed from starting
            return newHead;
        }
        return head; // original head
    }
};