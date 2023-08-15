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
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL) return NULL;
        if(head ->next == NULL) return head;
        
        ListNode*dummy1 = NULL;
        ListNode*tail1 = dummy1;
        ListNode*temp = head;


        ListNode*dummy2 = NULL;
        ListNode*tail2 = dummy2;

        while(temp != NULL){
            if(temp -> val < x){
                if(dummy1 == NULL){
                    dummy1 = temp;
                    tail1 = dummy1;
                }
                else{
                    tail1 -> next = temp;
                    tail1 = tail1 -> next;
                }
            }
            else if(temp -> val >= x){
                if(dummy2 == NULL){
                    dummy2 = temp;
                    tail2 = dummy2;
                }
                else{
                    tail2 ->next = temp;
                    tail2 = tail2 -> next;
                }
            }
            temp = temp -> next;
        }

        if(dummy2 == NULL){
            tail1 -> next = NULL;
            return dummy1;
        }
        if(dummy1 == NULL){
            tail2 -> next = NULL;
            return dummy2;
        }
        tail1 -> next = dummy2;
        tail2 -> next = NULL;
        return dummy1;
    }
};