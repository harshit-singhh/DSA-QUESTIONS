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

    int solve(TreeNode*root , int &maxi){
        if(root == NULL) return 0;

        int left = solve(root -> left , maxi);
        int right = solve(root -> right , maxi);

        int currlen = left + right + 1;
        maxi = max(currlen , maxi);
        return max(1 + left , 1 + right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi = INT_MIN;
        solve(root , maxi);
        return maxi-1;
    }
};