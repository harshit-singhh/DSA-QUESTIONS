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
      vector<vector<int>> ans;
      queue<pair<TreeNode*,pair<int,int>>> q;
      map<int,map<int,multiset<int>>> m;
      if(root == NULL)
        return ans;
      q.push({root,{0,0}});
      while(!q.empty())
      {
          auto it = q.front();
          q.pop();
          TreeNode* t = it.first;
          int v = it.second.first;
          int l = it.second.second;
          m[v][l].insert(t->val);
          if(t->left)
            q.push({t->left,{v-1,l+1}});
        if(t->right)
            q.push({t->right,{v+1,l+1}});
      }  

      for(auto it : m)
      {
          vector<int> temp;
          for(auto i : it.second)
          {
              for(auto j: i.second)
              {
                  temp.push_back(j);
              }
          }
          ans.push_back(temp);
      }
      return ans;
    }
};