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
    ListNode* deleteMiddle(ListNode* head) {
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    
    if(head -> next -> next == NULL){
        head -> next = NULL;
        return head;
    }
    
    ListNode*slow = head;
    ListNode*fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    ListNode*temp = head;
    
    while(temp -> next != slow){
        temp = temp -> next;
    }
    
    temp -> next = slow -> next;
    slow -> next = NULL;
    
    
    return head;
    }
};