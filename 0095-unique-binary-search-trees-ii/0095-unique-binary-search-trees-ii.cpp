class Solution {
public:
    vector<TreeNode*> fn(int start,int end){
        vector<TreeNode*> res;
        //case when left or right subtree for a given node cant be generated 
        if(start>end) return {NULL};
        //case when there is only one node 
        if(start==end) return {new TreeNode(start)};
        
        for(int i=start;i<=end;i++){
            //generate all left subtrees when i is the root 
            vector<TreeNode*> left=fn(start,i-1);
            // all right subtrees when i is the root 
            vector<TreeNode*> right=fn(i+1,end);
            
            for(auto lnode:left){
                //for every left subtree with root=i, add all rightsubtrees to it
                for(auto rnode:right){
                    TreeNode *root=new TreeNode(i,lnode,rnode);
                    res.push_back(root); //store one unique BST as result 
                }
                    
            }
        }
        
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res=fn(1,n);
        return res;
    }
};