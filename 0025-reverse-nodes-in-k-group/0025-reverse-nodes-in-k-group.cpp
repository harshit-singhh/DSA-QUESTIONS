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
    int findsize(ListNode*head){
        ListNode*temp = head;
        int size = 0;
        while(temp!= NULL){
            size++;
            temp = temp -> next;
        }
        return size;
    }
    vector<ListNode*> reverseNode(ListNode*head , int k){
        ListNode*curr = head;
        ListNode*prev = NULL;
        ListNode*forw = NULL;

        while(k){
            k--;
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }

        return {curr , prev};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        int size = findsize(head);
        if(size < k ) return head;

        vector<ListNode*>nodes = reverseNode(head , k);
        head -> next = reverseKGroup(nodes[0] , k);
        return nodes[1];
    }
};