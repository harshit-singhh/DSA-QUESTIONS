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
    TreeNode*solve(vector<int>&preorder , vector<int>&inorder ,int is , int ps ,
    int ie , int pe,int n, unordered_map<int ,int>&mp){

        if(ps > pe || is > ie) return NULL;
        

        TreeNode*root = new TreeNode(preorder[ps]);
        int index = mp[preorder[ps]];
        int len = index - is;
        root -> left = solve(preorder , inorder , is , ps+1 ,index-1,ps+ len,n, mp);
        root -> right = solve(preorder , inorder, index+1 ,ps+len + 1, ie , pe, n, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }

        int is = 0 , ps = 0 , ie = n-1 , pe = n-1;
        TreeNode*root = solve(preorder , inorder , is , ps , ie , pe , n , mp);

        return root;
    }
};





// map<int,int>m;
//     TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
//         for(int i=0;i<in.size();i++){
//             m[in[i]]=i;
//         }
//         TreeNode* root = build(pre,0,pre.size()-1,in,0,in.size()-1);
//         return root;
//     }
//     TreeNode* build(vector<int>&pre,int preStart,int preEnd,vector<int>&in, int inStart,int inEnd){
//         if(preStart>preEnd || inStart>inEnd)return NULL;
//         TreeNode* root = new  TreeNode(pre[preStart]);
//         int index = m[pre[preStart]];
//         int len = index - inStart;
//         root->left = build(pre,preStart+1,preStart+len,in,inStart,index-1);
//         root->right = build(pre,preStart+len+1,preEnd,in,index+1,inEnd);
//         return root;
//     }