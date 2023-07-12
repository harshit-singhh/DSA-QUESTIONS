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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

			
      int count = 0;
    	queue<TreeNode*>p;
    	
    	vector<vector<int>>ans; // to store the reversed and non reversed numbers
			if(root == NULL) return ans;
    	
    	p.push(root);
    	
    	while(!p.empty()){
    	    vector<int>level;
    	    
    	    int size = p.size();
    	    
    	    for(int i = 0 ; i< size ; i ++){
    	        TreeNode*temp = p.front();
    	        p.pop();
    	        // if (temp != NULL) {
    	        if(temp -> left != nullptr) p.push(temp -> left);
    	        if(temp -> right!= nullptr ) p.push(temp -> right);
    	        
    	        level.push_back(temp -> val);
							
    	        
    	        
    	    }
    	    
    	    if(count%2 == 0) ans.push_back(level);
    	    else{
    	        reverse(level.begin(),level.end());
    	        ans.push_back(level);
    	    }
    	    count++;
 
    	}

        return ans;
    }
};