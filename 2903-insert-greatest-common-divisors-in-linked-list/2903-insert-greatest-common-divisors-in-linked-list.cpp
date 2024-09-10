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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head -> next == NULL) return head;
        
        ListNode*curr = head;
        ListNode*prev = NULL;
        
        while(curr -> next != NULL){
            prev = curr;
            if(curr -> next != NULL){
                curr = curr -> next;
            }
            
            int prevVal = prev -> val;
            int currVal = curr -> val;
            
            int gcd = __gcd(prevVal , currVal);
            
            ListNode* neww = new ListNode(gcd);
            
            neww -> next = curr;
            prev -> next = neww;
        }
        
        return head;
        
        
    }
};