class Solution {
    bool dfs(vector<int>adj[],vector<int>&colors , vector<int>&visited ,int node , int color){
        visited[node] = 1;
        colors[node] = color;

        for(auto it: adj[node]){
            if(visited[it] == 0){
                int newcolor = 1 - colors[node];
                if(dfs(adj , colors , visited , it , newcolor) == false) return false;
            }
            else if(colors[it] == colors[node]) return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];

        for(int i = 0 ; i < n ; i++){
            
            for(auto it : graph[i]){
                adj[i].push_back(it);
            }
        }

        vector<int>color(n);
        vector<int>visited(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(visited[i] == 0){

                if(dfs(adj , color , visited , i , 0)== false) return false; 
            }

        }

        return true;
    }
};