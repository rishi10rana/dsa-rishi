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
    // Approach -1 Using length of node and divide by 2 to get mid node position 
    // T.C = O(n + n/2)
    /*
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            length++;
            temp = temp->next;
        } 

        temp = head;
        int count = 0;
        while(count < length/2){
            temp = temp->next;
            count++;
        }
        return temp;
    }
    */

    // Approach 2 T.C = O(n/2) = O(n)
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){ // to ddeal with single node or no node case
            return head;
        }

        // no need to hanld this case as algo will handle it
        // if(head->next->next = NULL){ // todeal with only 2 node case
        //     return head->next;
        // }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            slow = slow->next; // moves 1 step at a time
            if(fast->next!=NULL){
                fast=fast->next->next; // move two step at a time
            }
            else{
                fast=fast->next; // move 1 step at time due to even case
            }
        }
        // when the fast reaches null which is after the last node at that time slow only reaches till mid node
        return slow;
    }
};