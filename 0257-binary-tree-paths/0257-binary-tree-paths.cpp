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
    void solve(TreeNode*root , string temp , vector<string>&ans, bool &first){
        if(root == NULL )return;

        int val = root -> val;
        string str = to_string(val);
        
        if(first == false)temp+="->";
        first = false;
        temp+=str;

        solve(root -> left , temp , ans , first);
        
        solve(root -> right , temp , ans , first);

        if(root -> left == NULL && root -> right == NULL ) ans.push_back(temp);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp = "";
        vector<string>ans;

        bool first = true;
        solve(root , temp , ans , first);

        
        return ans;
    }
};