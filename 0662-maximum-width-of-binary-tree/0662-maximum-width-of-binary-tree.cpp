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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode* , int>>q;

        q.push({root , 0});

        int maxi = 0;

        while(!q.empty()){
            int size = q.size();
            int first;
            int last;
            int firstNodeNum = q.front().second;
            for(int i = 0 ; i < size ; i ++){
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                int num = it.second;

                int normalizednum = num - firstNodeNum;

                if(i == 0 ) first = normalizednum;
                if(i == size-1) last = normalizednum;

                if(node -> left != NULL){
                    q.push({node -> left , (long long)normalizednum*2 + 1});

                }
                if(node -> right != NULL){
                    q.push({node -> right , (long long)normalizednum*2 + 2});
                }
            }

            maxi = max(maxi , (last - first + 1));
        }

        return maxi;
    }
};