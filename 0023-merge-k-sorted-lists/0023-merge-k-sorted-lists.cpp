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
        
        priority_queue<ListNode* , vector<ListNode*> , comp>q;

        for(auto it : lists){
            ListNode*temp = it;
            while(temp != NULL){
                q.push(temp);
                temp = temp -> next;
            }
        }

        ListNode*dummy = new ListNode(-1);
        ListNode*temp = dummy;
        while(!q.empty()){
            
            ListNode*currNode = q.top();
            currNode -> next = NULL;
            q.pop();

            temp -> next = currNode;
            temp = temp -> next;

        }

        return dummy -> next;

    }
};