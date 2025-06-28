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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // get total no of nodes in list
        int totalNodes = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            totalNodes++;
            temp = temp->next;
        } 

        // means deleting first node
        if(n==totalNodes){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // for other cases find position to go at to delete
        int position = totalNodes - n;

        // place current and prev at correct postion
        ListNode* currentNode = head;
        ListNode* prevNode = NULL;
        int count = 0;
        while(count < position){
            prevNode = currentNode;
            currentNode = currentNode->next;
            count++;
        }

        // delete the currentNode
        prevNode->next = currentNode->next;
        currentNode->next = NULL;
        delete currentNode;
        
        return head;
    }
};