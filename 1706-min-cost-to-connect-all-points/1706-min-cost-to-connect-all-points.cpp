class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<pair<int,int>>adj[n];

        for(int i = 0 ; i< n ; i++){
            
            for(int j = 0 ; j < n ; j++){
                if(j == i) continue;
                
                int manhattanDistance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j , manhattanDistance});
            }
        }

        // prims algo

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>q;
        q.push({0 , 0});
            // wt , node
        
        vector<int>visited(n , 0);

        int ans = 0;

        while(!q.empty()){
            auto it =  q.top();
            q.pop();

            int weight = it.first;
            int node = it.second;

            if(visited[node] == 1) continue;
            visited[node] =1;
            ans+= weight;

            for(auto it: adj[node]){
                int nbr = it.first;
                int edgeWeight = it.second;

                if(!visited[nbr]){
                    q.push({edgeWeight , nbr});
                }
            }
        }

        return ans;
    }
};