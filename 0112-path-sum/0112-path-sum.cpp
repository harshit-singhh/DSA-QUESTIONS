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

    bool isLeaf(TreeNode*root){
        return !((root -> left) || (root -> right));
    }
    bool solve(TreeNode*root , int targetSum){
        if(root == NULL) return false;
        if(isLeaf(root) && targetSum - (root -> val) == 0) return true;

        targetSum -= root -> val;
        bool left = solve(root -> left , targetSum );
        bool right = solve(root -> right , targetSum );

        return left || right;

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root , targetSum);
    }
};