class Solution {
    void solve(unordered_map<int ,vector<int>>&mp , int parent , int node , vector<int>&ans){
        ans.push_back(node);

        for(auto it: mp[node]){
            if(it != parent){
                solve(mp , node , it , ans);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        

         unordered_map<int , vector<int>>mp;

         for(auto it: arr){
             int u = it[0];
             int v = it[1];

             mp[u].push_back(v);
             mp[v].push_back(u);
         }

        int node;
         for(auto it: mp){
             
             int size = 0;

             for(auto k : it.second){
                 size++;
                 if(size > 1) break;
             }

             if(size > 1) continue;
             else if(size == 1){
                 node = it.first;
                 break;
             }
         }

         vector<int>ans;

         solve(mp , -1 , node , ans);
         return ans;
    }
};