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

class isbst{
    public:
    long long maxi;
    long long mini;
    long long isvalid;

    isbst(long long maxi , long long mini , bool isvalid){
        this -> maxi = maxi;
        this -> mini = mini;
        this -> isvalid = isvalid;
    }
};

class Solution {
public:

    isbst solve(TreeNode*root){
        if(root == NULL ) return {LLONG_MIN , LLONG_MAX , true};


        isbst left = solve(root -> left);
        isbst right = solve(root -> right);

        if(left.isvalid == false || right.isvalid == false){
            return {0 , 0, false};
        }
        
        bool valid;
        if(root -> val > left.maxi && root -> val < right.mini){
            valid = true;
        }
        else valid = false;

        return {max((long long) root -> val , right.maxi) , min((long long )root-> val , left.mini) , valid};
        
    }

    bool isValidBST(TreeNode* root) {
        
        isbst ans = solve(root);
        return ans.isvalid;
    }
};