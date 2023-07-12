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

    private:
    int findsum(TreeNode*root , int& maxSum){
        if(root == NULL) return 0;
        
        int left = findsum(root -> left , maxSum);
        int right = findsum(root ->right , maxSum);
        
        int sum = max(left,right)+root->val; // ya to node left side se aane wale sum max hoga ya fir node + right side
        
        int sum2 = left+right+root->val; // ya ho sakta he left + node + right side ka sum max ho
        
        int sum3 = root->val; // ya ho sakta he ki left, right side se -ve values aa rhi ho, to us case me agar node ki value
        // plus dono me se kisi side se bhi aane wale data ko add krenge to aur -ve number aa jaega. there fore in this case 
        
        // node ka data will be max
        
        maxSum = max(maxSum,max(sum,max(sum2,sum3)));
        
        return max(sum,sum3);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findsum(root,maxSum);
        return maxSum;
    }
};