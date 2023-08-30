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
    
    
    ListNode*reverse(ListNode*head){
        ListNode*curr = head;
        ListNode*prev = NULL;
        ListNode*forward = NULL;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    void insertAttail(ListNode*&anshead, ListNode*&anstail,int digit){
        ListNode*temp = new ListNode(digit);
        if(anshead == NULL){
            anshead = temp;
            anstail = temp;
            return;
        }
        else{
            anstail -> next = temp;
            anstail = anstail -> next;
            // anstail = temp;
            return;
        }
    }
    
    ListNode*add( ListNode*first,  ListNode*second){
        int carry = 0;
        int sum;
        
        ListNode*anshead = NULL;
        ListNode*anstail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int value1 = 0;
            if(first != NULL){
                value1 = first -> val;
            }
            int value2 = 0;
            if(second != NULL){
                value2 = second -> val;
            }
            
            sum = carry + value1 + value2;
            int digit = sum%10;
            insertAttail(anshead,anstail,digit);
            carry = sum/10;
            
            if(first != NULL){
                first = first -> next;
            }
            if(second != NULL){
                second = second -> next;
            }
        }
            return anshead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head = add(l1 , l2);
        return head;
    }
};