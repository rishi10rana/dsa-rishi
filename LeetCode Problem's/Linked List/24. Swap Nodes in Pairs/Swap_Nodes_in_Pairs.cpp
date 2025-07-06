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
    // T.C = O(n) , S.C = O(1)
    ListNode* swapPairs(ListNode* head) {
        // edge case no node or 1 single node
        if(head==NULL || head->next == NULL){
            return head;
        }

        // point the new head
        ListNode* newHead = head->next;
        ListNode* current = head;
        ListNode* prev = NULL; // track the last node of the previously swwapped pair
        while(current!=NULL && current->next!=NULL){
            ListNode* first = current;
            ListNode* second = current->next;
            // store the next pair where we would go
            ListNode* nextPair = second->next;

            // swapping
            second->next = first;
            first->next = nextPair;
            if(prev!=NULL){
                prev->next = second;
            }
            prev = first;
            current = nextPair; // move to next pair
        }

        return newHead;
    }
};