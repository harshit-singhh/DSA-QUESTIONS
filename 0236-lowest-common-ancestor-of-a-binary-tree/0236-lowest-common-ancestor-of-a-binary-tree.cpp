/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode*solve(TreeNode*root , TreeNode*p , TreeNode*q){
        if(root == NULL ) return NULL;
        if(root == p) return p;
        if(root == q) return q;

        TreeNode*left = solve(root -> left , p , q);
        TreeNode*right = solve(root -> right , p , q);

        if(left != NULL && right != NULL ) return root;
        else if(left == NULL && right != NULL ) return right;
        else return left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return solve(root , p , q);
    }
};