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
        int size = 0;

        ListNode*temp = head;

        while(temp != NULL){
            size++;
            temp = temp ->next;
        }

        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL) return head;
        if(k == 0) return head;
        int size = findsize(head);
        cout<<size<<endl;
        if(k >= size){
            k%=size;
        }
        if(k == 0){
            return head;
        }



        int to_travel = (size - k) - 1;

        ListNode*temp = head;
        while(to_travel > 0){
            temp = temp -> next;
            to_travel--;
        }

        ListNode*newhead = temp -> next;

        ListNode*newtemp = newhead;

        while(newtemp-> next != NULL){
            newtemp = newtemp -> next;
        }

        temp -> next = NULL;
        newtemp -> next = head;

        return newhead;
    }
};