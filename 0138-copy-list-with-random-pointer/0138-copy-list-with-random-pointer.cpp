/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL ) return NULL;

        Node*copyhead;
        Node*tempcopy = NULL;

        Node*temp = head;
        unordered_map<Node*,Node*>mp;

        while(temp){
            if(tempcopy == NULL){
                copyhead = new Node(temp -> val);
                tempcopy = copyhead;
                mp[temp] = tempcopy;
            }
            else{
                Node*newcopynode = new Node(temp -> val);
                tempcopy -> next = newcopynode;
                tempcopy = tempcopy -> next;
                mp[temp] = tempcopy;

            }

            temp = temp -> next;
        }

        tempcopy -> next = NULL;

        temp = head;
        tempcopy = copyhead;
        while(temp){
            tempcopy -> random = mp[temp -> random];
            tempcopy = tempcopy-> next;
            temp = temp -> next;
        }

        return copyhead;

    }
};