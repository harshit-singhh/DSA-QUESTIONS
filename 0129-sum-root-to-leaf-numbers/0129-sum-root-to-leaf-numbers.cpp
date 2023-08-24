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
    int solve(TreeNode*root , int ans){
        if(root == NULL) return 0;

        ans = ans*10 + root -> val;

        int left = solve(root -> left , ans);
        int right = solve(root -> right , ans);
        
        if(left == 0 && right == 0) return ans;
        if(right == 0) return left;
        if(left == 0) return right;
        else return left + right;
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root , 0);
    }
};