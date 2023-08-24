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
    bool solve(TreeNode*root1 , TreeNode*root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL && root2 != NULL) return false;
        if(root1 != NULL && root2 == NULL) return false;

        bool left = solve(root1 -> left , root2 -> right);
        bool right = solve(root1 -> right , root2 -> left);

        if(root1 -> val == root2 -> val && left && right) return true;

        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        bool ans = solve(root -> left , root -> right);
        return ans;
        
    }
};