class Trie {
    public:

    struct Node{
        
        Node*links[26];
        bool isLeaf;
        int childcount = 0;


        bool containsKey(char ch){
        
            if(links[ch - 'a'] != NULL) return true;
            return false;
        }

        void put(char ch , Node*node){
            links[ch - 'a'] = node;
        }

        Node*nextStop(char ch){

            return links[ch - 'a'];
        }

        void isend(){
            isLeaf = true;
        }

        bool checkEnd(){
            if(isLeaf == true) return true;
            return false;
        }

        void childcountIncrease(){
            childcount+=1;
        }
    };

    Node*getNode(){
        Node*newnode = new Node();

        for(int i = 0 ; i <26 ; i++) newnode -> links[i] = NULL;
        newnode -> isLeaf = false;

        return newnode;

        
    }

    Node*root;

    /** Initialize your data structure here. */
    Trie() {
        root = getNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node*temp = root;
        for(auto it : word){
            if(temp -> containsKey(it) == false){
                temp -> put(it , getNode());
                temp -> childcountIncrease();
            }
            temp = temp -> nextStop(it);
        }
        temp -> isend();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node*temp = root;
        for(auto it : word){
            if(temp -> containsKey(it) == false){
                return false;
            }
            temp = temp -> nextStop(it);
        }
        
        return temp -> checkEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node*temp = root;
        for(auto it : prefix){
            if(temp -> containsKey(it) == false){
                return false;
            }
            temp = temp -> nextStop(it);
        }
        return true;
    }

    string childcountKrooo(string word){
        Node*temp = root;
        string ans = "";
        int index = 0;
        while(index < word.size() && temp -> childcount == 1){
            ans.push_back(word[index]);
            char ch = word[index];
            
            index++;
            temp = temp -> nextStop(ch);
        }

        return ans;
    }
};

class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     string ans = "";
    //     int n = strs.size();
    //     if(strs.size() == 1){
    //         return strs[0];
    //     }
        
        
    //     for(int i = 0 ; i < strs[0].size() ; i++){
    //         char ch = strs[0][i];
    //         bool issame = true;

    //         for(int j = 1 ; j < n ; j++){
    //             if(strs[j][i] != ch){
    //                 issame = false;
    //                 break;
    //             }
                
    //         }
    //         if(issame) ans.push_back(ch);
    //         if(issame == false) break;
    //     }

    //     return ans;
    // }


    // trie

     string longestCommonPrefix(vector<string>& strs){
         Trie trie;
         string ans = "";

         sort(strs.begin(), strs.end());

         

         for(auto it: strs){
             if(it == ""){
                 return "";
             }
             trie.insert(it);
         }

         ans = trie.childcountKrooo(strs[0]);
         return ans;
     }
};