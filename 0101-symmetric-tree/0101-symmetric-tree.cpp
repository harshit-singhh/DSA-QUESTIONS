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

    bool isleaf(TreeNode*root){
        if(root -> left == NULL && root -> right == NULL) return true;
        return false;
    }

    bool solve(TreeNode*leftNode , TreeNode*rightNode){
        if(leftNode == NULL && rightNode == NULL ) return true;
        else if(leftNode == NULL && rightNode != NULL ) return false;
        else if(leftNode != NULL && rightNode == NULL ) return false;

        bool side1 = solve(leftNode -> left , rightNode -> right);
        bool side2 = solve(leftNode -> right , rightNode -> left);

        if(side1 == false || side2 == false ) return false;
        if(leftNode -> val != rightNode -> val ) return false;
        return true;

    }

    bool isSymmetric(TreeNode* root) {
        if(isleaf(root)){
            return true;
        }

        return solve(root -> left , root -> right);
    }
};