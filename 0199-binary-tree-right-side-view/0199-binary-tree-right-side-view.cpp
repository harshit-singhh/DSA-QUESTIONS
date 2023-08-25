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
        vector<int>ans;

        if(root == NULL) return {};

        map<int,int>mp;

        queue<pair<TreeNode*, int>>q;

        q.push({root , 0});

        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i < size ; i ++){
                auto it = q.front();
                q.pop();

                TreeNode* temp = it.first;
                int level = it.second;

                if(mp.find(level) == mp.end()){
                    mp[level] = temp -> val;
                }

                if(temp -> right != NULL ) q.push({temp -> right , level+1});
                if(temp -> left != NULL) q.push({temp -> left , level + 1});
            }

            
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;

        
    }
};