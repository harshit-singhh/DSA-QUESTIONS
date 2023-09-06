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
    private:

    int findsize(ListNode*temp){

        int size = 0;

        while(temp){
            size++;
            temp = temp-> next;
        }

        return size;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ListNode*temp = head;
        int size = findsize(temp);
        int partsize = size / k;
        int extra = size % k;
        // temp = head;
        vector<ListNode*>vec;
        int i = 0;
        while(i < k){
            
            if(extra){
                while(extra){
                    i++;
                    vec.push_back(temp);
                    int to_travel = partsize;
                    while(to_travel){
                        size--;
                        temp = temp -> next;
                        to_travel--;
                    }
                ListNode* nextnode = temp -> next;
                temp -> next = NULL;
                temp  = nextnode;
                extra--;
                }
            }
            else if(temp != NULL){
            
                vec.push_back(temp);
                i++;
                int to_travel = partsize - 1;
                while(to_travel){
                    size--;
                    temp = temp-> next;
                    to_travel--;
                }
                ListNode*nextnode = temp -> next;

                temp -> next = NULL;
                temp = nextnode;

            }

            else{
                vec.push_back(NULL);
                i++;
            }

        }

        return vec;

    }
};