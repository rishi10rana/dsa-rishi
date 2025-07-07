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
    // To find totol length of linked list
    int getLength(ListNode* head){
        int length = 0;
        while(head!=NULL){
            length++;
            head = head->next;
        }
        return length;
    }

    // helps to find the end node for a group 
    ListNode* getKthNode(ListNode* head, int k){
        k = k - 1; // ex - k =2 we need to run ony [1] time 
        while(head!=NULL && k>0){
            head = head->next;
            k--;
        }
        return head;
    }

    // helps to reverse a given grouip of linked list 
    // takes startnode and reverse till it find NULL
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current!=NULL){
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current =  nextNode;
        }
        return prev; // this is the new head of reversed list
    }

    // T.C = O(n) as no of groups will be fixed
    ListNode* reverseKGroup(ListNode* head, int k) {
        // case if no node or ek ek node a group hai
        if(head==NULL || k==1){
            return head;
        }

        int length = getLength(head);
        // create a dummy node jis ke aage answer wala node add karna
        ListNode* dummy = new ListNode(0);

        // to traverse now to find k groups
        ListNode* prev = dummy;
        ListNode* current = head;
        // jab tak kth groups we can get
        while(length >= k){ 
            ListNode* start = current;
            ListNode* end = getKthNode(current,k);
            
            // agar end null ban gaya means group cant be made further so break the loop
            if(end==NULL){
                break;
            }
            // to keep track of nextStart
            ListNode* nextStart = end->next;

            // to reverse till we get NULL (disconenc the group temporary)
            end->next = NULL;

            // now reverse the group and attach it to prev ka next;
            prev->next = reverse(current);

            // also to make sure that even if the loop breaks if we cant find kth grouo
            // futher at that time conenct the remaing nodes at last 
            start->next = nextStart;

            prev = start;
            current = nextStart;
            length = length - k; // as k group elements reversed
        }

        // as we dont want dummy node we want the list in front of it
        return dummy->next; 
    }
};