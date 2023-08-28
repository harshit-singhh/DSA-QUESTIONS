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
    TreeNode*solve(vector<int>&postorder , vector<int>&inorder ,int is , int ps ,
    int ie , int pe,int n, unordered_map<int ,int>&mp){

        if(ps > pe || is > ie) return NULL;
        

        TreeNode*root = new TreeNode(postorder[pe]);
        int index = mp[postorder[pe]];
        int len = index - is;
        root -> left = solve(postorder , inorder , is , ps ,index-1,ps+ len -1,n, mp);
        root -> right = solve(postorder , inorder, index+1 ,ps+len, ie , pe -1, n, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }

        int is = 0 , ps = 0 , ie = n-1 , pe = n-1;
        TreeNode*root = solve(postorder , inorder , is , ps , ie , pe , n , mp);

        return root;
    }
};


















// class Solution {
// public:
//     map<int,int>m;
//     TreeNode* buildTree(vector<int>& in, vector<int>& post) {
//         for(int i=0;i<in.size();i++)m[in[i]]=i;
//         TreeNode* root = build(in,0,in.size()-1,post,0,post.size()-1);
//         return root;
//     }
//     TreeNode* build(vector<int>&in, int inS,int inE,vector<int>&post,int postS,int postE){
//         if(inS>inE || postS>postE)return NULL;
//         TreeNode* root = new TreeNode(post[postE]);
//         int index = m[post[postE]];
//         int len = inE - index;   
//         root->right = build(in,index+1,inE,post,postE-len,postE-1);
//         root->left = build(in,inS,index-1,post,postS,postE-len-1);
//         return root;
//     }
// };