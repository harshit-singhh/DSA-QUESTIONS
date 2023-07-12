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

    int maxDiam(TreeNode* root, int& maxi) {
        if (root == NULL)
            return 0;

        int leftHeight = maxDiam(root->left, maxi);
        int rightHeight = maxDiam(root->right, maxi);

        // Update the diameter if the longest path passes through the root
        int diameter = leftHeight + rightHeight;
        maxi = max(maxi, diameter);

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0; 
        maxDiam(root,maxi);
        return maxi;
    }
};