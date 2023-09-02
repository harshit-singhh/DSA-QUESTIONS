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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            bool isnull = false;
            bool notnull = false;

            for(int i = 0 ; i < size ; i++){
                TreeNode*temp = q.front();
                q.pop();

                if(temp == NULL){
                    isnull = true;
                    continue;
                }

                if(temp != NULL && isnull == true) return false;

                q.push(temp -> left);
                if(temp-> left != NULL) notnull = true;
                q.push(temp -> right);
                if(temp -> right != NULL) notnull = true;

            }
            if(isnull == true && notnull == true) return false;
                
            
        }
        return true;
    }
};