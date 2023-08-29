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
    ListNode*reverse(ListNode*head){
        ListNode*curr = head;
        ListNode*prev = NULL;
        ListNode*forward = NULL;
        
        while(curr){
            forward = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
    
        ListNode*temp = head;

        int size = 0;

        while(temp){
            size++;
            temp = temp -> next;
        }
        vector<int>ans(size);

        stack<int>st;

        head = reverse(head);
        temp = head;
        int index = size-1;
        while(temp){
            while(!st.empty() && temp -> val >= st.top()){
                st.pop();
            }
            if(st.empty()){
                ans[index] = 0;
                st.push(temp -> val);
            }
            else if(!st.empty()){
                ans[index] = st.top();
                st.push(temp -> val);
            }
            temp = temp -> next;
            index--;
        }

        return ans;


    }
};