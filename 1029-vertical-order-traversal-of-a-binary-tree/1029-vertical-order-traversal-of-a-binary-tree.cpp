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

    vector<vector<int>> verticalTraversal(TreeNode* root){

        vector<vector<int>>ans;

        map<int , vector<pair<int,int>>>mp;

        queue<pair<TreeNode* , pair<int,int>>>q;

        q.push({root , {0 , 0}});
        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i < size ; i++){
                auto it = q.front();
                q.pop();
                
                TreeNode*temp = it.first;
                int value = it.first -> val;
                int xaxis = it.second.first;
                int level = it.second.second;

                mp[xaxis].push_back({level , value});

                if(temp -> left != NULL) q.push({temp -> left , {xaxis - 1 , level + 1}});
                if(temp -> right != NULL)q.push({temp -> right , {xaxis + 1 , level + 1}});
                
            }
        }

        for(auto it : mp){
            sort(it.second.begin() , it.second.end());

            vector<int>temp;
            for(auto k : it.second){
                temp.push_back(k.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


























// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//       vector<vector<int>> ans;
//       queue<pair<TreeNode*,pair<int,int>>> q;
//       map<int,map<int,vector<int>>> m;
//       if(root == NULL)
//         return ans;
//       q.push({root,{0,0}});
//       while(!q.empty())
//       {
//           auto it = q.front();
//           q.pop();
//           TreeNode* t = it.first;
//           int v = it.second.first;
//           int l = it.second.second;
//           m[v][l].push_back(t->val);
//           if(t->left)
//             q.push({t->left,{v-1,l+1}});
//         if(t->right)
//             q.push({t->right,{v+1,l+1}});
//       }  

//       for(auto it : m)
//       {
//           vector<int> temp;
//           for(auto i : it.second)
//           {
//               for(auto j: i.second)
//               {
//                   temp.push_back(j);
//               }
//           }
//           ans.push_back(temp);
//       }
//       return ans;
//     }
// };