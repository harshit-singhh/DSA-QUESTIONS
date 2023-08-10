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
        private:
        vector<TreeNode*>solve(int start , int end ,map<pair<int , int> , vector<TreeNode*>>&m){
            vector<TreeNode*>res;
            if(start == end){
                TreeNode* root = new TreeNode(0);
                return {root};
            }

            if(m.find({start ,end}) != m.end()) return m[{start , end}]; 

            for(int i = start ; i <= end ; i++){
                if(i%2 == 0){
                    vector<TreeNode*>Leftbst = solve(start , i-1 , m);
                    vector<TreeNode*>Rightbst = solve(i+1 , end , m);

                    for(auto left : Leftbst){
                        for(auto right : Rightbst){
                            TreeNode* root = new TreeNode(0);
                            root -> left = left;
                            root -> right = right;
                            res.push_back(root);
                        }
                    }
                }
            }
            return m[{start , end}] = res;

        }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0) return {};

        map<pair<int ,int> , vector<TreeNode*>>m;
        vector<TreeNode*>res = solve(1 , n , m);
        return res;
    }
};