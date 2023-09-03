class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // int n = edges.size();

        // unordered_map<int,int>mp;

        // for(auto it: edges){
        //     int u = it[0];
        //     int v = it[1];

        //     mp[u]++;
        //     mp[v]++;
        // }

        // int ans;
        // for(auto it: mp){
        //     if(it.second == n){
        //         ans = it.first;
        //         break;
        //     }
        // }

        // return ans;
        int ans;
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ans = edges[0][0];
        else if(edges[0][1] == edges[1][0] || edges[0][1] == edges[1][1]) ans =edges[0][1];

        return ans;

    }
};