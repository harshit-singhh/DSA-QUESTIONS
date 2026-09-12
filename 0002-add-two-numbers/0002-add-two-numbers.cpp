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
    void addinNode(int digit , ListNode*&temp){

        temp -> next = new ListNode(digit);
        temp = temp -> next;
        
    }
    ListNode*addnum(ListNode*l1 , ListNode*l2){
        ListNode*head = new ListNode(-1);
        ListNode*temp = head;

        int carry = 0;

        while(l1 != NULL || l2 != NULL){
            int l1num = 0;
            int l2num = 0;
            if(l1 != NULL ) l1num = l1 -> val;
            if(l2 != NULL ) l2num = l2 -> val;

            int sum = l1num + l2num + carry;
            carry = sum / 10;
            int digit = sum % 10;
            addinNode(digit , temp); 

            if(l1!= NULL ) l1 = l1 -> next;
            if(l2 != NULL ) l2 = l2 -> next;
        }

        if(carry != 0 ) {
            addinNode(carry , temp);
        }

        return head -> next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode*head = addnum(l1 , l2);
        return head;
    }
};