bool comp(pair<int , pair<int ,int >>a , pair<int , pair<int ,int >>b){

    return a.second.second < b.second.second;
}


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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        Trie*trie = new Trie();

        sort(nums.begin() , nums.end());

        vector<pair<int , pair<int ,int >>>store;

        int n = queries.size();

        for(int i = 0 ; i < n;  i++){
            store.push_back({i , {queries[i][0] , queries[i][1]}}); //storing the real index and the x , m value
        }

        sort(store.begin() , store.end() , comp);

        vector<int>ans(n);

        int index = 0;

        for(int i = 0 ; i < n ; i++){
            int element = store[i].second.first;
            int range = store[i].second.second;
            int correctIndex = store[i].first;

            while(index < nums.size() && nums[index] <= range){
                trie->insert(nums[index]);
                index++;
            }
            if(index == 0) ans[correctIndex] = -1;
            else ans[correctIndex] = trie->getMax(element);
        }

        return ans;

    }
};