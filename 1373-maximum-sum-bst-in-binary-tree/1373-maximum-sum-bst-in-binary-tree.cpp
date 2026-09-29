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

class validbst{
    public:

    int maxi;
    int mini;
    bool isvalid;
    int sum;

    validbst(int maxi , int mini , bool isvalid , int sum){
        this -> maxi = maxi;
        this -> mini = mini;
        this -> isvalid = isvalid;
        this -> sum = sum;
    }
};
class Solution {
public:
    validbst solve(TreeNode*root , int& maxsum){
        if(root == NULL) return {INT_MIN , INT_MAX , true , 0};

        validbst left = solve(root -> left , maxsum);
        validbst right = solve(root -> right, maxsum);

        int leftmaxsum = left.sum;
        int rightmaxsum = right.sum;
        int currsum = 0;

        if(root -> val > left.maxi && root -> val < right.mini && left.isvalid && right.isvalid ){
            currsum += leftmaxsum + rightmaxsum + root->val;
            maxsum = max(maxsum , currsum);
            return {max(right.maxi , root->val) , min(left.mini , root->val) , true , currsum};
        }
        else return {max(right.maxi , root -> val) , min(left.mini , root->val) , false , max(leftmaxsum , max(0 , rightmaxsum)) };



    }
    int maxSumBST(TreeNode* root) {
        int maxsum = 0;
        validbst ans = solve(root , maxsum);
        return maxsum;
    }
};