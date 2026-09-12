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

    ListNode*findmid(ListNode*head){
        
        ListNode*fast = head;
        ListNode*slow = head;

        while(fast -> next != NULL && fast -> next -> next != NULL && slow != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;

        }
        return slow;
    }

    ListNode*solve (ListNode*left , ListNode*right){
        ListNode*head = NULL;
        ListNode*temp = head;

        while(left != NULL && right != NULL ){
            if(left -> val <= right -> val){
                if(head == NULL){

                    head = left;
                    temp = head;
                } 
                else{
                    temp -> next = left;
                    temp = temp -> next;
                } 
                left = left -> next;
                
                
            }
            else{
                if(head == NULL){

                    head = right;
                    temp = head;
                } 
                else{
                    temp -> next = right;
                    temp = temp -> next;
                } 
                right = right -> next;
            }
        }

        if(left == NULL && right != NULL ) {
            temp -> next = right;
        }
        else if(left != NULL && right == NULL) {
            temp -> next = left;
        }

        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL ) return NULL;
        if(head -> next == NULL ) return head;
        ListNode*mid = findmid(head);
        ListNode*left = head;
        ListNode*right = mid-> next;
        mid -> next = NULL;
        left = sortList(left);
        right = sortList(right);
        head = solve(left , right );
        return head;
        
    }
};