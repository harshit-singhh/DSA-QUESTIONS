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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        insertleft(root);
    }
    
    int next() {
        TreeNode*top = st.top();
        st.pop();
        if(top -> right){
            st.push(top -> right);
            insertleft(top -> right);
        }

        return top -> val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }

    void insertleft(TreeNode*root){
        
        TreeNode*temp = st.top();
        temp = temp -> left;
        while(temp){
            st.push(temp);
            temp = temp -> left;
        }
    }
};



// class BSTIterator {
// private: stack<TreeNode*>st;
// public:
//     BSTIterator(TreeNode* root) {
//         pushAll(root,st);
//     }
    
//     int next() {
//         TreeNode*temp = st.top();
//         st.pop();
//         pushAll(temp -> right,st);
//         return temp -> val;
//     }
    
//     bool hasNext() {
//         if(!st.empty())return true;
//         return false;
//     }

//     void pushAll(TreeNode*root, stack<TreeNode*>&st){
//         while(root != NULL){
//             st.push(root);
//             root = root -> left;
//         }
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */