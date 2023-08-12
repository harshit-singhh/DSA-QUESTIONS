
struct Node{
    Node*links[2];
    

    bool containsKey(int bit){
        if(links[bit] != NULL) return true;
        else return false;
    }

    // now to add the node , if it was not present
    void put(int bit , Node*node){
        links[bit] = node;
    }
};
class Trie {
    Node*root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node*node = root;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = (num >> i) & 1;
            if(!node -> containsKey(bit)){
                node -> put(bit , new Node());
            }
            node = node -> links[bit];
        }
    }
    
    int getMax(int num){
        Node*node = root;
        int maxNum = 0;
        for(int i = 31 ; i >= 0 ; i--){
            
            int bit = (num >> i) & 1;
            // we will check that if the node contains the opposite of it
            if(node -> containsKey(1 - bit)){ // if it contains then 
                maxNum = maxNum | (1 << i);
                node = node -> links[1 - bit];
            }
            else{
                node = node -> links[bit]; 
            }
            
            
        }
        
        return maxNum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {
        Trie*trie = new Trie();
        int n = arr.size();
        
        for(int i = 0 ; i < n ; i++){
            trie->insert(arr[i]);
        }
        
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , trie ->getMax(arr[i]));
        }
        return maxi;
    }
};