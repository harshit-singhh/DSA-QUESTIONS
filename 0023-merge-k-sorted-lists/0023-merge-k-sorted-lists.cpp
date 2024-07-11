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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n  = lists.size();

        priority_queue<pair<int , ListNode*> , vector<pair<int , ListNode*>> , greater<pair<int,ListNode*>>>q;

        for(int i = 0 ; i < n ;i++){

            if(lists[i] != NULL){

                ListNode*temp = lists[i];
                while(temp != NULL){

                    int data = temp -> val;
                    q.push({data , temp});
                    temp = temp -> next;
                }

            }
        }

        ListNode*head = new ListNode(-1);
        ListNode*temp = head;

        while(!q.empty()){
            auto it = q.top();
            q.pop();

            temp -> next = it.second;
            temp = temp -> next;
        }

        return head-> next;
    }
};