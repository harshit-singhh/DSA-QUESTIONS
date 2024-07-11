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

    ListNode*merge(ListNode*head1 , ListNode*head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL )return head1;

        if(head1-> val <= head2 -> val){
            head1-> next = merge(head1->next , head2);
            return head1;
        }
        else{
            head2-> next = merge(head2-> next , head1);
            return head2;
        }
        return NULL;
    }

    ListNode* breakk(vector<ListNode*>lists , int start , int end){
        if(start == end) return lists[start];

        int mid = start + (end - start )/2;

        ListNode*left = breakk(lists , start , mid);
        ListNode*right = breakk(lists,mid+1 , end);

        return merge(left , right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        
        
        if (n == 0) return nullptr;
        return breakk(lists, 0 , n-1);

        


    }
};