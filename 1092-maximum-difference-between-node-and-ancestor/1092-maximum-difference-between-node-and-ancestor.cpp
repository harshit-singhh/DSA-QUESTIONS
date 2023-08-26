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
    pair<int,int> solve(TreeNode*root , int&maxi){
        if(root == NULL )return {-1e9 , 1e9};

        pair<int ,int >left = solve(root -> left , maxi);
        pair<int ,int> right = solve(root -> right , maxi);

        int value = root -> val;

        int currmax = max(value , max(left.first , right.first));
        int currmin = min(value , min(left.second , right.second));

        maxi = max(maxi , max(value - currmin , currmax - value));

        return {currmax, currmin};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        
        int maxi = INT_MIN;
        solve(root , maxi);
        return maxi;
    }
};