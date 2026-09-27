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
public:
    TreeNode* findnextgreater(TreeNode*root){
        TreeNode*temp = root;

        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL ) return NULL;
        
        if(root -> val > key){
            root -> left = deleteNode(root -> left , key);
            return root;

        }
        else if(root -> val < key){
            root -> right = deleteNode(root -> right , key);
            return root;
        }

        // 0 nodes
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // 2 nodes
        else if(root -> left != NULL && root -> right != NULL){
            TreeNode* nextGreater = findnextgreater(root -> right);
            root -> val = nextGreater -> val;
            root -> right = deleteNode(root -> right , root -> val);

            return root;
        }

        else{
            if(root -> left != NULL){
                TreeNode*leftNode = root -> left;
                delete root;
                return leftNode;
            }
            else if(root -> right != NULL){
                TreeNode*rightNode = root -> right;
                delete root;
                return rightNode;
            }
        }

        return root;
    }
};