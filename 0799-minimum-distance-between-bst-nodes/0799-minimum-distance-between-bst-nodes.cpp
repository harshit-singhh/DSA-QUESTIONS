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
    void solve(TreeNode*root , int&ans , TreeNode* &prev){
        if(root == NULL) return;

        solve(root -> left , ans , prev);
        if(prev == NULL){
            prev = root;

        }
        else{
            ans = min(ans , root -> val - prev -> val);
            prev = root;
        }
        solve(root -> right , ans , prev);
    }
public:
    int minDiffInBST(TreeNode* root) {
        if(!root ) return 0;
        int ans = INT_MAX;

        TreeNode* prev = NULL;

        solve(root , ans , prev);
        return ans;
    }
};