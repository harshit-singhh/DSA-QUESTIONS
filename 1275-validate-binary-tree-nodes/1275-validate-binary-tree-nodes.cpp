class Solution {
public:
    // Depth-First Search to check if the given nodes form a valid binary tree
    bool isBinaryTreeValid(int current, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited) {
        // Check left child
        if (leftChild[current] != -1) {
            if (visited[leftChild[current]]) // Check for cycle
                return false;
    
            visited[leftChild[current]] = true; // Mark left child as visited
            if(!isBinaryTreeValid(leftChild[current], leftChild, rightChild, visited))
                return false;
        }
    
        // Check right child
        if (rightChild[current] != -1) {
            if (visited[rightChild[current]]) // Check for cycle
                return false;
    
            visited[rightChild[current]] = true; // Mark right child as visited
            if(!isBinaryTreeValid(rightChild[current], leftChild, rightChild, visited))
                return false ;
        }
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> childCount(n, false); // Tracks child count for each node

        // Update child count based on leftChild
        for (auto child : leftChild) {
            // Check if node has child
            if (child != -1)
                childCount[child] = true; // Mark left child as having a parent
        }

        // Update child count based on rightChild
        for (auto child : rightChild) {
            // Check if node has child
            if (child != -1) {
                if (childCount[child]) // Check if the right child already has a parent
                    return false;

                childCount[child] = true; // Mark right child as having a parent
            }
        }

        int root = -1; // Root node
        for (int i = 0; i < n; ++i) {
            if (!childCount[i]) {
                if (root == -1)
                    root = i; // Set root node if not assigned
                else
                    return false; // Multiple roots found, not a valid binary tree
            }
        }

        if (root == -1)
            return false; // No root found, not a valid binary tree

        
        vector<bool> visited(n) ; // Tracks visited nodes
        visited[root] = true ;
        if(!isBinaryTreeValid(root, leftChild, rightChild, visited)) // Check if the tree is valid
            return false ;

        // Check if there is multiple components
        for(int i = 0 ; i < visited.size() ; i ++)
            if(!visited[i])
                return false ;

        return true; // All nodes form a valid binary tree
    }
};


// class Solution {
//     private:
//     void dfs(vector<int>adj[] , vector<int>&visited , int node){
//         visited[node] = 1;

//         // int drow[] = {-1 , 0 , 1 , 0};
//         // int dcol[] = { 0 , -1 , 0 , 1};

//         for(auto it: adj[node]){
//             if(visited[it]== 0){
//                 dfs(adj , visited, it);
//             }
//         }        
//     }
// public:
//     bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
//         vector<int>adj[n];

//         // child parent
//         unordered_map<int,int>mp;

//         for(int i = 0 ; i < n ; i++){
            
//             int leftchild = leftChild[i];
//             int rightchild = rightChild[i];

//             if(mp.find(leftchild) == mp.end()){
//                 if(leftchild != -1) mp[leftchild] = i;
//             }
//             else return false;
//             if(mp.find(rightchild) == mp.end()){
//                 if(rightchild != -1) mp[rightchild] = i;
//             }
//             else return false;


//         }

//         int root = -1;

//         for(int i = 0 ; i < n ; i++){
//             if(mp.find(i) == mp.end()){
//                 if(root != -1){
//                     return false;
//                 }
//                 root = i;
//             }
//         }

//         if(root == -1) return false;


//         // making adjecency list

//         for(int i = 0 ; i < n ; i++){
//             int leftchild = leftChild[i];
//             int rightchild = rightChild[i];
//             if(leftchild != -1) adj[i].push_back(leftchild);
//             if(rightchild != -1) adj[i].push_back(rightchild);
//         }

//         int components = 0;

//         vector<int>visited(n , 0);
//         for(int i = 0 ; i < n ; i++){
//             if(visited[i] == 0 ){
//                 components++;
//                 dfs(adj , visited, i);
//             }
//         }

//         if(components != 1) return false;
//         return true;

//     }
// };