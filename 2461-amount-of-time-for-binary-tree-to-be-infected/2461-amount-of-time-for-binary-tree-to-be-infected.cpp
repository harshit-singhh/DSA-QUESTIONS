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
    void findparent(TreeNode*root , unordered_map<TreeNode*,TreeNode*>&mp){
        if(root == NULL )return ;

        if(root -> left != NULL) mp[root -> left] = root;
        findparent(root -> left , mp);
        if(root -> right != NULL) mp[root -> right] = root;
        findparent(root -> right , mp);
    }

    TreeNode*findstart(TreeNode*root , int start){
        if(root == NULL )return NULL;

        TreeNode*left = findstart(root -> left , start);
        TreeNode*right = findstart(root -> right , start);

        if(left != NULL) return left;
        if(right != NULL) return right;

        if(root -> val == start) return root;
        return NULL;
    }
    int amountOfTime(TreeNode* root, int start) {
        int maxi = INT_MIN;

        unordered_map<TreeNode* , TreeNode*>parent;

        unordered_map<TreeNode* , bool >visited;

        findparent(root , parent);

        TreeNode* startt = findstart(root , start);

        queue<TreeNode*>q;
        q.push(startt);
        visited[startt] = true;


        int count = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i < size ; i ++){
                TreeNode*temp = q.front();
                q.pop();

                visited[temp] = true;
                if(temp -> left && visited[temp -> left] == false) q.push(temp -> left);
                if(temp -> right && visited[temp -> right] == false) q.push(temp -> right);
                if(parent.find(temp) != parent.end() && visited[parent[temp]] == false) q.push(parent[temp]);

            }
            count++;
        }
        return count-1;
    }
};