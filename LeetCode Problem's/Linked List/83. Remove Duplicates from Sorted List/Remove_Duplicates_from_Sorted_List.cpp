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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        while(temp!=NULL && temp->next!=NULL){ // compare node and uska aage wala
            if(temp->val==temp->next->val){
                temp->next = temp->next->next;
            }
            else{ // if the two nodes compared are different (to amintain check)
            // to make sure no duplicate even after performing operation
                temp = temp->next;
            }
        }
        return head;
    }
};