/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode*solve(TreeNode*root , TreeNode*p , TreeNode*q ){
        if(root == NULL) return NULL;

        TreeNode*left = NULL;
        TreeNode*right = NULL;
        if(root -> val > p -> val && root -> val > q -> val){
            left = solve(root -> left , p , q);
        }
        else if(root -> val < p -> val && root -> val < q -> val){
            right = solve(root -> right , p , q);
        }
        else{
            return root;
        }

        if(left!= NULL) return left;
        else return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return solve(root , p ,q);
    }
};



// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL) return NULL;
            
//         if(root -> val == p->val) return root;
//         if(root -> val == q->val) return root;
            
//         TreeNode*left = lowestCommonAncestor(root -> left , p, q);
//         TreeNode*right = lowestCommonAncestor(root -> right , p, q);
            
//         if(left != NULL && right != NULL) return root;
            
//         if(left != NULL) return left;
//         else if(right != NULL) return right;
//         else return NULL;
//     }
// };