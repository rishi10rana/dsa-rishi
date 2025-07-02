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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Case 1 - Any one of the list is empty then reteurn the other list
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        // Choose final list ke liya head jo sabse chota element hona chahiye dono list ke first wale se choose karo
        ListNode* head = NULL;
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }

        // traverse to form the rest of the list
        ListNode* temp = head;
        // loop stop kardena agar koii ek bhi list puri traverse hojayae
        while(list1!=NULL && list2!=NULL){
            // list1 ya list2 mei se jo chota hoga usse next node bana do temp ki
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; // yaha tak pahuch gaya matlab ek node to add kar diya to fir temp ko aage badha do
        }

        // Lost Possible Case ki koii ek list phela empty hogayi aur dusri list bach gayi
        // to jo bach gayi use temp ke next mei add kardo
        // jo list phela null tak pahuch gayi wo khatam hogayi to dusri list jo  bachi use add kardo
        temp->next = (list1==NULL) ? list2 : list1;

        return head;
    }
};