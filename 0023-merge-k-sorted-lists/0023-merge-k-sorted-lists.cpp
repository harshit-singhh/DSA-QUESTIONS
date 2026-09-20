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
    ListNode* mergeLeftRight(ListNode*left , ListNode*right){

        if(right == NULL ) return left;
        if(left == NULL ) return right;

        while(left != NULL && right != NULL){

            if(left -> val <= right -> val){
                left -> next = mergeLeftRight(left -> next , right);
                return left;
            }
            else{
                right -> next = mergeLeftRight(left , right -> next);
                return right;
            } 
        }
        return NULL;
    }
    ListNode*splitandsort(vector<ListNode*>&lists , int start , int end){
        if(start > end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }

        int mid = start + ( end - start ) / 2;

        ListNode*left = splitandsort(lists, start , mid);
        ListNode*right = splitandsort(lists , mid+1 , end);

        ListNode*mergedHead = mergeLeftRight(left , right);
        return mergedHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        return splitandsort(lists , 0 , n-1);

    }
};