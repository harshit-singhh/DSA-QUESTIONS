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
    vector<int> largestValues(TreeNode* root) {
        
        if(root == NULL )return {};
        queue<TreeNode*>q;
        
        q.push(root);
        
        vector<int>ans;
        
        // ans.push_back(root -> data);
        
        while(!q.empty()){
            int size = q.size();
            int maxi = INT_MIN;
            
            for(int i = 0 ; i < size  ; i++){
                TreeNode*temp = q.front();
                q.pop();
                
                maxi = max(maxi , temp -> val);
                
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL )q.push(temp -> right);
            }
            ans.push_back(maxi);
        }
        
        return ans;
    }
};