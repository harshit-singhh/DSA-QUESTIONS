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
    void solve(TreeNode*root , map<int, map<int,vector<int>>>&mp , int x , int level){
        if(root == NULL ) return;
        mp[x][level].push_back(root -> val);

        solve(root -> left , mp , x-1 , level+1);
        solve(root -> right , mp , x+1 , level+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int,vector<int>>>mp;

        solve(root , mp , 0 , 0);

        vector<vector<int>>ans;

        for(auto it : mp){
            
            vector<int>temp;
            for(auto k : it.second){

                vector<int>arr = k.second;
                sort(arr.begin() , arr.end());
                for(auto it : arr) temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};