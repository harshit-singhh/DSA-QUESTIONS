class Node{
    public:
    Node*next;
    Node*prev;
    string page;

    Node(string homepage){
        this -> page = homepage;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class BrowserHistory {
    Node*head;
    Node*temp;
    Node*curr = NULL;
public:
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        temp = head;
        curr = temp;

    }
    
    void visit(string url) {
        Node* newnode = new Node(url);
        temp -> next = newnode;
        newnode -> prev = temp;
        temp = temp -> next;
        
    }
    
    string back(int steps) {
        while(temp -> prev !=  NULL && steps > 0){
            temp = temp -> prev;
            steps--;
        }

        return temp -> page;


    }
    
    string forward(int steps) {
        
        while(temp -> next != NULL && steps > 0 ){
            temp = temp -> next;
            steps--;
        }

        return temp -> page;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */