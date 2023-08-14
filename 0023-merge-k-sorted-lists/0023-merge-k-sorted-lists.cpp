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
 class comp{
     public:
     bool operator()(const ListNode*a , const ListNode*b){
         return a -> val > b -> val;
     }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , comp> p;

        for(auto it: lists){
            ListNode*temp = it;
            while(temp!= NULL){
                p.push(temp);
                temp = temp-> next;
            }
        }

        ListNode*head = new ListNode(-1);
        ListNode*temp = head;

        while(!p.empty()){
            temp -> next = p.top();
            temp = temp -> next;
            p.pop();
        }

        temp -> next = NULL;
        return head -> next;
    }
};