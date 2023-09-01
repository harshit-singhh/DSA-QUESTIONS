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

class BSTiterator{
    public:
    stack<TreeNode*>st;
    bool reverse;

    BSTiterator(TreeNode*root , bool isreversed){
        this -> reverse = isreversed;
        st.push(root);
        insertElement(root);
    }

    int next(){
        if(reverse == false){
            TreeNode*temp = st.top();
            st.pop();
            if(temp -> right){
                st.push(temp -> right);
                insertElement(temp -> right);
            }
            return temp -> val;
        }
        else{
            TreeNode*temp = st.top();
            st.pop();
            if(temp -> left){
                st.push(temp -> left);
                insertElement(temp -> left);

            }
            return temp -> val;
        }
    }

    void insertElement(TreeNode*node){
        if(reverse == false){
            TreeNode*temp = node->left;
            while(temp){
                st.push(temp);
                temp = temp -> left;
            }
        }
        else{
            TreeNode*temp = node -> right;
            while(temp){
                st.push(temp);
                temp = temp -> right;
            }
        }
    }

};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTiterator* front = new BSTiterator(root , false);
        BSTiterator* reverse = new BSTiterator(root , true);

        int i = front -> next();
        int j = reverse -> next();
        

        while(i < j){
        
            if(i + j == k) return true;
            if(i + j < k){
                i = front -> next();
            }
            else j = reverse -> next();
        }
        return false;

    }
};




// class Solution {
//     void solve(TreeNode* root, vector<int> & inorder){
//         if(root==NULL)
//             return ;
//             // LNR
//         solve(root->left,inorder);
//         inorder.push_back(root->val);
//         solve(root->right,inorder);
//     }
// public:
//     bool findTarget(TreeNode* root, int k) {
//         vector<int> inorder;
//         solve(root,inorder);
//         int s=0,e=inorder.size()-1;
//         int sum=0;
//         while(s<e)
//         {
//             sum=inorder[s]+inorder[e];
//             if(sum==k)
//                 return true;
//             else if (sum>k)
//                 e--;
//             else
//                 s++;
//         }
//         return false;
//     }
// };