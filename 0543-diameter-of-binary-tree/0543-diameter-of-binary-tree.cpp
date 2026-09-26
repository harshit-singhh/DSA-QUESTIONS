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
    int solve(TreeNode*root , int&maxi){
        if(root == NULL ) return 0;

        int leftsize = solve(root -> left , maxi);
        int rightsize = solve(root -> right , maxi);

        int dia1 = leftsize + 1;
        int dia2 = rightsize + 1;
        int dia3 = leftsize + rightsize + 1;

        maxi = max(maxi , dia3);
        return max(dia1 , dia2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int value = solve(root , maxi);
        return maxi-1;

    }
};