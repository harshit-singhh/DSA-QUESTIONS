/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    bool solve(vector<TreeNode*>store , TreeNode*root , int index , int n , map<pair<TreeNode* , int>, bool>&mp){
        if(index == n) return true;
        if(root == NULL )return false;

        if(mp.find({root , index}) != mp.end()) return mp[{root , index}];

        bool left;
        bool right;
        if(root -> val == store[index] -> val){
            left = solve(store , root -> left , index+1 , n , mp) || solve(store , root-> left , 0 , n , mp);
            right = solve(store ,root -> right , index+1 , n , mp) || solve(store , root -> right , 0 ,n , mp);
        }
        else{
            left = solve(store , root -> left , 0 , n , mp);
            right = solve(store , root -> right , 0 , n , mp);
        }

        if(left == true || right == true) return mp[{root , index}]=  true;
        return mp[{root , index}] = false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        vector<TreeNode*>store;

        ListNode*temp = head;

        map<pair<TreeNode* , int> , bool>mp;

        while(temp != NULL ){
            store.push_back(new TreeNode(temp -> val));
            temp = temp -> next;
        }

        temp = head;

        int size = store.size();

        int index = 0;

        return solve(store , root , 0 , size , mp);

    }
};