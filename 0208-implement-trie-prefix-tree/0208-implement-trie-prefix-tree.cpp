class Trie {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode*children[26];

    };
    // function to create new trie Node
    trieNode*getNode(){

        trieNode*newNode = new trieNode();
        // new node ka isend of word will be false
        newNode -> isEndOfWord = false;
        // new node ke sare children null ko point krenge initially
        for(int i = 0; i < 26 ; i++){
            newNode -> children[i] = NULL;
        }
        return newNode;
    }

    trieNode*root = new trieNode();


    // Trie() {
    //     root = getNode();   
    // }
    
    void insert(string word) {
        // now we will make a crawler which will traverse on all the nodes
        // initially it will be on root node

        trieNode*crawler = root;

        for(int i = 0 ; i < word.size() ; i++){
            char ch = word[i];
            int index = ch-'a';

            if(crawler -> children[index] == NULL){ // us index pe null pda he therefore hme bnana pdega new node
                crawler -> children[index] = getNode(); // suppose word is 'apple' , so a ke liye node ban chuki he
            }
            crawler = crawler -> children[index]; // crawler aage badhta jaega
        }
        // now ye pura loop jab khatam ho jaega tab hamara pura letter insert ho chuka hoga
        // and crawler hmare word ke last letter ko point kar rha hoga -> apple ke "e" ko in this case

        crawler -> isEndOfWord = true;
        
    }


    // now search ka code bhi insert se same same sa hi hoga
    
    bool search(string word) {

         trieNode*crawler = root;

        for(int i = 0 ; i < word.size() ; i++){
            char ch = word[i];
            int index = ch-'a';

            if(crawler -> children[index] == NULL){ // agar null mil gya then this means ki ko word he hi nhi,
                return false;
            }
            crawler = crawler -> children[index]; 
        }

        // loop ke baad agar hmara isEndOfWord == true he , then this means ki esa koi element
        // insert hua tha

        // but agar false he then this means ki esa koi element insert hi nhi hua tha so return false

        if(crawler -> isEndOfWord == true) return true;
        else return false;
        
    }
    
    bool startsWith(string prefix) {
         trieNode*crawler = root;

        //eg full word was apple , prefix to find is app .
        for(int i = 0 ; i < prefix.size() ; i++){ // apan root node se start krenge
            char ch = prefix[i];
            int index = ch-'a';

            if(crawler -> children[index] == NULL){
                // agar koi element nhi milta then this means ki not present therefore return false
                return false;
            }
            crawler = crawler -> children[index]; 
        }
        
        // agar for loop ke bahar aa gae , and false return nhi hua then this means ki word present hi hoga tabhi to false return nhi hua

        // therefore return true

        return true;
    }
};

// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */






// STRIVER CODE

// struct Node{
//     Node*links[26];
//     bool flag = false;

//     bool containsKey(char ch){
//         if(links[ch-'a'] != NULL) return true;
//         else return false;
//     }

//     // now to add the node , if it was not present
//     void put(char ch , Node*node){
//         links[ch-'a'] = node;
//     }
// };
// class Trie {
//     Node*root;
// public:
//     Trie() {
//         root = new Node();
//     }
    
//     void insert(string word) {
//         Node*node = root;
//         for(auto it : word){
//             if(!node ->containsKey(it)){ // if the node does not contain the letter then create a new node and wo us letter ko dedo.
//                 node->put(it , new Node());
//             }
//             // move to the next node
//             node = node -> links[it - 'a'];
//         }
//         node -> flag = true;
//     }
    
//     bool search(string word) {
//         Node*node = root;
//         for(auto it : word){
//             if(!node -> containsKey(it)){
//                 return false;
//             }
//             node = node->links[it - 'a'];
//         }

//         if(node -> flag == true) return true;
//         return false;
//     }
    
//     bool startsWith(string prefix) {
//         Node*node = root;
//         for(auto it : prefix){
//             if(!node -> containsKey(it)){
//                 return false;
//             }
//             node = node->links[it - 'a'];
//         }
//         return true;
        
//     }
// };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */