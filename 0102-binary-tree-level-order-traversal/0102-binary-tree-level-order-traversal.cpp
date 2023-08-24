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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == NULL) return {};
        queue<TreeNode*>q;

        q.push(root);

        vector<vector<int>>ans;
        ans.push_back({root->val});

        while(!q.empty()){
            int size = q.size();
            vector<int>store;

            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();

                q.pop();

                if(temp-> left != NULL) q.push(temp -> left) , store.push_back(temp -> left -> val);
                if(temp -> right != NULL) q.push(temp -> right), store.push_back(temp -> right -> val);


            }
            if(store.size() != 0) ans.push_back(store);
            else break;
        }

        return ans;
    }
};