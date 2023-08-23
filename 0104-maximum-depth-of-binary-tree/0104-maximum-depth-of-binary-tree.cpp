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
    void solve(TreeNode*root , int&maxi , int height){
        if(root == NULL) return;

        height+=1;
        maxi = max(maxi , height);
        solve(root -> left , maxi , height);
        solve(root -> right , maxi , height);
    }
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL) return 0;
        int maxi = INT_MIN;
        int height = 0;

        solve(root , maxi , height);

        return maxi;
    }
};