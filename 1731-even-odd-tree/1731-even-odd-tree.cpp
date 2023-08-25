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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*>q;

        q.push(root);

        int count = 0;
        int prev;
        while(!q.empty()){
            int size = q.size();
            vector<int>store;
            if(count%2 == 0){
                prev = -1;
            }
            if(count%2 == 1){
                prev = INT_MAX;
            }
            bool first = true;
            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();

                if(count%2 == 0){
                    if(temp -> val %2 == 1 && temp -> val > prev){
                        prev = temp -> val;
                    }
                    else return false;
                }

                if(count%2 == 1){
                    if(temp -> val %2 == 0 && temp -> val < prev){
                        prev = temp -> val;

                    }
                    else return false;
                }

                q.pop();

                if(temp-> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);

            }
            count++;
        }

        return true;
    
    }
};