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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            bool firstElem = true;
            for(int i = 0 ;  i < size ; i++){
                auto it = q.front();
                q.pop();

                TreeNode*temp = it;
                if(firstElem == true){
                    ans.push_back(temp -> val);
                    firstElem = false;
                }

                if(temp -> right) q.push(temp -> right);
                if(temp -> left) q.push(temp -> left);

            }
        }

        return ans;
    }
};