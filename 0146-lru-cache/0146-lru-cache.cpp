class Node {
public:
    int key, value;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int a, int b) {
        this->key = a;
        this->value = b;
    }
};

class LRUCache {
public:
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->cap = capacity;
        // Connect dummy head and tail
        head->next = tail;
        tail->prev = head;
    }

    // Helper: Add node right after head
    void addNode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Helper: Unlink a node from the list
    void deleteNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* resnode = mp[key];
        deleteNode(resnode);
        addNode(resnode);

        return resnode->value;
    }

    void put(int key, int value) {
        // Case 1: Key already exists -> update value and move to head
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            existingNode->value = value;
            deleteNode(existingNode);
            addNode(existingNode);
            return;
        }

        // Case 2: Capacity reached -> evict LRU node (tail->prev)
        if (mp.size() == cap) {
            Node* lruNode = tail->prev;
            mp.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode; // Free memory
        }

        // Insert brand new key
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};