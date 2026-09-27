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
    int index = 0;
    TreeNode* solve(vector<int>&preorder , int maxi , int mini){
        if(index >= preorder.size() || preorder[index] >= maxi || preorder[index] <= mini )return NULL;

        TreeNode*node = new TreeNode(preorder[index]);
        index++;
        node -> left = solve(preorder , node -> val , mini);
        node -> right = solve(preorder , maxi , node -> val);

        return node;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return solve(preorder , INT_MAX , INT_MIN);
    }
};