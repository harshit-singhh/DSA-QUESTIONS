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
    int solve(TreeNode*root , int&maxi){
        if(root == NULL ) return 0;

        int leftsum = solve(root -> left , maxi);
        int rightsum = solve(root -> right , maxi);

        int rootVal= root -> val;

        int sum1 = rootVal;
        int sum2 = rootVal + max(leftsum , rightsum);
        int sum3 = rootVal + leftsum + rightsum;

        maxi = max(maxi , max(sum1 , max(sum2 , sum3)));
        return max(sum1 , sum2);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int value = solve(root , maxi);
        return maxi;
    }
};