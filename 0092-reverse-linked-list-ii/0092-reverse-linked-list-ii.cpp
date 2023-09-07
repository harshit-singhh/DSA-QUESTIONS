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
    private:
    ListNode*reverse(ListNode*head){
        ListNode*curr = head;
        ListNode*prev = NULL;
        ListNode*forward;

        while(curr != NULL){
            forward = curr -> next;
            curr -> next= prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*curr = head;
        ListNode*prev = NULL;
        int count = 1;
        while(count < left){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        ListNode*start = curr;

        while(count < right){
            curr = curr -> next;
            count++;
        }
        ListNode*remaining = curr -> next;
        curr-> next = NULL;

        ListNode*newhead = reverse(start);
        curr = newhead;
        while(curr -> next != NULL) curr = curr -> next;
        curr -> next = remaining;

        if(prev != NULL) prev -> next = newhead;

        if(left == 1) return newhead;
        else return head;

        

    }
};