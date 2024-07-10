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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int , map<int , vector<int>>>mp;

        queue<pair<TreeNode* , pair<int,int>>>q;

        q.push({root , {0 , 0}});

        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i < size ; i ++){

                auto it = q.front();
                q.pop();

                TreeNode*root = it.first ;
                int xLevel = it.second.second;
                int depth = it.second.first;


                mp[xLevel][depth].push_back(root -> val);

                if(root -> left) q.push({root -> left , {depth+1 , xLevel-1}});
                if(root -> right) q.push({root -> right , {depth+1 , xLevel + 1}});

            }
        }


        vector<vector<int>>ans;

        for(auto it: mp){
            vector<int>temp;
            for(auto k : it.second){
                sort(k.second.begin() , k.second.end());
                for(auto j : k.second){
                    temp.push_back(j);
                }
            }

            ans.push_back(temp);
        }

        return ans;


    }
};