class LRUCache {
public:

// Make a class of Node which contain key,value,Prev ptr,next ptr.
class Node{
public:
    int key,val;
    Node* prev;
    Node* next;
    Node(int _key,int _val){
        key=_key;
        val=_val;
    }
};
int cap; // to check the capacity of the map

unordered_map<int,Node*>mp; // make a map of int and Node* type , basically Node* stores the address of the node

Node* head=new Node(-1,-1); // make a head with value -1,-1.
Node* tail=new Node(-1,-1); // make a tail with value -1,-1.

    LRUCache(int capacity) {
        cap=capacity; // capacity scope in only in this loop so store it in cap
        head->next=tail; // make a link head->tail and tail->prev becaue of DLL(double Linked list)
        tail->prev=head;
    }
// Do dry for better understanding

    // I need to add newNode right after the head,
    void addNode(Node* newNode){
        Node* temp=head->next; // store the head next 
        // and then made 4 links, because of dll
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }

    void deleteNode(Node* delNode){
        // store prev of delNode and nextNode and then delete and form the link For DLL.
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNode->next;
        delNext->prev=delNode->prev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){ // if it is present in map
            Node* resNode=mp[key]; // store the address of mp of key
            int res=resNode->val; // store the val of the address
            deleteNode(resNode); // delete that node
            addNode(resNode); // add that node 
            mp[key]=head->next; // now mp of key contain new address
            return res;
        }   
        return -1;  // if not present in map
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){ // if it is already in map 
            Node* existingNode=mp[key]; // fin d the address
            mp.erase(key);// erase it from map
            deleteNode(existingNode); // delete it 
        }
        if(mp.size()==cap){ // it size equals delete the LRU node which is at tail->prev
            mp.erase(tail->prev->key); 
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value)); // add then new node with the key,value right after head
        mp[key]=head->next; // change the new address of map of key with head->next
    }
};
