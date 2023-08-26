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
    TreeNode*solve(TreeNode*root1 , TreeNode*root2 , TreeNode*root3){
        if(!root1 && !root2) return NULL;
        if(root1 == NULL && root2 != NULL )return root2;
        if(root1 != NULL && root2 == NULL) return root1;

        TreeNode*left = solve(root1 -> left , root2 -> left , root3 -> left);
        TreeNode*right = solve(root1 -> right , root2 -> right , root3 -> right);

        root3 -> left = left;
        root3 -> right = right;
        if(root1 != NULL && root2 != NULL ) root3 -> val = root1 ->val + root2 -> val;
        return root3;

    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode*root3 = root1;

        root3 = solve(root1 , root2 , root3);  
        return root3; 
    }
};