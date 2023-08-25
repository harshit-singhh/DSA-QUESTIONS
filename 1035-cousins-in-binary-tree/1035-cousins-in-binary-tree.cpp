/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void parent(TreeNode*root , int element , int currparent , int&realparent){
        if(root == NULL) return;
        
        parent(root -> left , element , root -> val ,realparent);
        if(root -> val == element){
            realparent = currparent;
            return;
        }
        parent(root -> right , element , root -> val ,realparent);
    
    
    }


    int height(TreeNode*root , int element , int depth){
        if(root == NULL) return 0;
        
        int left = height(root -> left , element , depth+1);
        if(root -> val == element){
            return depth;
        }
        int right = height(root -> right , element , depth+1);
        
        if(left != 0) return left;
        if(right != 0) return right;
        return 0;
        
    }
public:
    bool isCousins(TreeNode* root, int a, int b) {
    int parent1 = -1;
    int parent2 = -1;
    
    parent(root , a , -1 , parent1);
    parent(root , b , -1  , parent2);
    
    int h1 = height(root , a , 0);
    int h2 = height(root , b , 0);
    
    if(h1 == h2 && parent1 != parent2) return true;
    return false;
    }
};