/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Approach 2 - no extra space , TT.C = O(n)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL; // cant get intersection
        }

        ListNode* a = headA;
        ListNode* b = headB;
        while(a!=b){

            // this makes both of them cover same distance after they start treversing together
            // and are able to find intersection if any
            a = (a==NULL) ? a = headB : a->next;
            b = (b==NULL) ? b = headA : b->next;
        }
        return a;

    }



    // Approach 1 Using set - T.C - O(n)
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;

        // traverse all nodes in A and mark hem in set by adding them
        ListNode* temp = headA;
        while(temp!=NULL){
            st.insert(temp);
            temp = temp->next;
        }

        // traverse all nodes in B and if any node macth which is in set then
        // at that node intersection happens
        temp = headB;
        while(temp!=NULL){
            if(st.find(temp)!=st.end()){
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }
    */
};