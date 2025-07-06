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
    // final merge list ka head return karke dega
    ListNode* mergeTwoSortedList(ListNode* list1,ListNode* list2){
        // agr koii ek L.L empty hui too
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        // decide the head of merged list (sabse chota wala)
        ListNode* head;
        if(list1->val<=list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        
        // travese in both LL to find minimunm node and add that first
        ListNode* current = head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                current->next = list1;
                list1 = list1->next;
            }
            else{
                current->next = list2;
                list2 = list2->next;
            }
            current= current->next;
        }
        // add any remaining list 
        current->next = (list1==NULL)?list2:list1;
        return head; // headh of final merged list
    }

    // T.C = O(m * n)    S.C = O(1)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // their are no linked list to merge
        if(lists.size()==0){
            return NULL;
        }

        // This will everytime take a new L.L from lists and merge it with previous result
        ListNode* result = lists[0];
        for(int i=1;i<lists.size();i++){
            result = mergeTwoSortedList(result,lists[i]);
        }

        return result;
    }
};