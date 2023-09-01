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
    void findinorder(TreeNode*root , vector<int>&inorder){
        if(root == NULL) return;

        findinorder(root-> left , inorder);
        inorder.push_back(root -> val);
        findinorder(root -> right , inorder);
    }

    TreeNode*maketree(vector<int>&inorder , int start , int end ){
        
        if(start > end) return NULL;
        int mid = start + ( end - start) /2;

        TreeNode*newnode = new TreeNode(inorder[mid]);

        newnode-> left = maketree(inorder, start , mid-1);
        newnode-> right = maketree(inorder,mid+1 , end);

        return newnode ;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;

        findinorder(root , inorder);

        int n = inorder.size();
        int start = 0;
        int end = n-1;

        TreeNode*head = maketree(inorder, start , end);
        return head;
    }
};