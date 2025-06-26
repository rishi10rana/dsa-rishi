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
    // T.C = O(N)
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* currentNode = head;
        ListNode* nextNode = NULL;

        while(currentNode!=NULL){
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        head = prevNode;
        return head;
    }


    /*
    // Recursive Solution 1 T.C = O(n)
    void solve(ListNode* &head,ListNode* current,ListNode* prev){
        // base case
        if(current==NULL){
            head = prev;
            return;
        }
        // to keep track of front nodes
        ListNode* forward = current->next;
        solve(head,forward,current);
        // on coming back from last during recursion
        current->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        solve(head,current,prev);
        return head;
    }
    */

    // Recursive Solution 2
    ListNode* reverseList(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* chotahead = reverseList(head->next); // basically head ko move kara raha till last node to make it head

        // while coming back
        head->next->next = head;
        head->next = NULL;

        // last mei chotahead jismei last node ko head bana kar dal diya tha wahi return kardo
        return chotahead;
    }
};