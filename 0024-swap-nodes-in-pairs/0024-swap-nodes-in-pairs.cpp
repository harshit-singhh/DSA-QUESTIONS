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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next== NULL) return head;
        ListNode*head1 = head;
        ListNode*temp1 = head1;
        ListNode*head2 = head -> next;
        ListNode*temp2 = head2;
        
        while(temp1 -> next != NULL && temp2 -> next != NULL){
            temp1 -> next = temp2 -> next;
            temp1 = temp1 -> next;
            temp2 -> next = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        if(temp1 != NULL)temp1 -> next = NULL;
        if(temp2 != NULL)temp2 -> next = NULL;
        
        temp1 = head1;
        temp2 = head2;
        
        while(temp2!= NULL && temp1 != NULL){
            
            if(temp2 -> next == NULL){
                temp2 -> next = temp1;
                break;
            }
            
            ListNode*next = temp2 -> next;
            temp2 -> next = temp1;
            temp2 = next;
            next = temp1 -> next;
            temp1 -> next = temp2;
            temp1 = next;
        }
        
        
        
        return head2;
    }
};