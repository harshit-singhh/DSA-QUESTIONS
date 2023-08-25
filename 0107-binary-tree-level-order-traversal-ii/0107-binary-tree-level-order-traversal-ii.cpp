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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*>q;

        q.push(root);

        vector<vector<int>>ans;
        

        while(!q.empty()){
            int size = q.size();
            vector<int>store;

            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();

                store.push_back(temp -> val);
                q.pop();

                if(temp-> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);


            }
            if(store.size() != 0) ans.push_back(store);
            else break;
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};