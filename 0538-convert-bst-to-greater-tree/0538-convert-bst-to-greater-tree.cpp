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
     void findInorder(TreeNode*root , vector<int>&inorder){
        if(root == NULL )return ;

        findInorder(root -> left , inorder);
        inorder.push_back(root -> val);
        findInorder(root -> right , inorder);
    }

    void newtree(TreeNode*root , vector<int>&suffix , int &index){
        if(root == NULL) return;

        newtree(root -> left , suffix , index);
        root -> val = suffix[index];
        index++;
        newtree(root -> right , suffix , index);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int>inorder;

        findInorder(root , inorder);
        int n =inorder.size();

        vector<int>suffix(n , 0);
        int sum = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            sum += inorder[i];
            suffix[i] = sum;

        }

        int index = 0;
        newtree(root , suffix , index);

        return root;
    }
};