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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL ) return NULL;
    ListNode*prev = head;
    ListNode*temp = head;
    
    while(temp){
        if(temp -> val == prev -> val){
            temp = temp -> next;
        }
        else{
            prev -> next = temp;
            prev = prev -> next;
            temp = temp -> next;
            
        }
    }
    prev -> next = NULL;
    return head;
    }
};