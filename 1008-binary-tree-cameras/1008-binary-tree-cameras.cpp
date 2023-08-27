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
     string solve(TreeNode*root , int&count){
        if(root == NULL) return "noneed";
        
        string left = solve(root -> left, count);
        string right = solve(root -> right, count);
        
        if(left == "want" || right == "want"){
            count++;
            return "providing";
        }
        if(left == "providing" || right == "providing"){
            return "noneed";
        }
        
        return "want";
    }
public:
    int minCameraCover(TreeNode* root) {
        int count = 0;
        if(solve(root , count) == "want") count+=1;
        return count;
    }
};