class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];

        for(auto it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int maxi = INT_MIN;
        for(int i = 0  ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int rank1 = adj[i].size();
                int rank2 = adj[j].size();

                int totalrank = rank1 + rank2;

                if(find(adj[i].begin() , adj[i].end() , j) != adj[i].end()) totalrank -= 1;
               
                maxi = max(maxi , totalrank);

                
            }
        }
        return maxi;


    }
};