
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>>q;

        q.push({root , {0,0}});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                int horval = it.second.first;
                int verval = it.second.second;

                mp[horval].push_back({verval , node -> val});

                if(node -> left) q.push({node -> left , {horval - 1 , verval + 1}});
                if(node -> right)q.push({node -> right , {horval+1 , verval + 1}});

            }
        }

        vector<vector<int>>ans;
        for(auto it : mp){
            vector<int>temp;
            sort(it.second.begin() , it.second.end());
            for(auto k : it.second){
                temp.push_back(k.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};