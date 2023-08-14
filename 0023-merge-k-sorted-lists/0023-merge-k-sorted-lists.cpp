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


 // heap method

//  class comp{
//      public:
//      bool operator()(const ListNode*a , const ListNode*b){
//          return a -> val > b -> val;
//      }
//  };
class Solution {
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1-> val <= list2 -> val){
            list1 -> next = mergeTwoLists(list1->next , list2);
            return list1;
        }
        else{
            list2-> next = mergeTwoLists(list2 -> next , list1);
            return list2;
        }
        return NULL;
    }

    ListNode*breakk(int start , int end , vector<ListNode*>& lists){
        if(start > end) return NULL;
        if(start == end) return lists[start];

        int mid = start + (end - start)/2;

        ListNode*left = breakk(start , mid , lists );
        ListNode*right = breakk(mid+1 , end ,  lists);

        return mergeTwoLists(left , right);
    }

public:
// heap method



//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode* , vector<ListNode*> , comp> p;

//         for(auto it: lists){
//             ListNode*temp = it;
//             while(temp!= NULL){
//                 p.push(temp);
//                 temp = temp-> next;
//             }
//         }

//         ListNode*head = new ListNode(-1);
//         ListNode*temp = head;

//         while(!p.empty()){
//             temp -> next = p.top();
//             temp = temp -> next;
//             p.pop();
//         }

//         temp -> next = NULL;
//         return head -> next;
//     }
// };

    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode* head = breakk(0 , lists.size()- 1 , lists);
        return head;
 
    }
};