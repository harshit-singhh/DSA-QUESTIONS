class Solution {
public:
    int timer = 0;
    void solve(vector<int>adj[] , vector<int>&visited , vector<vector<int>>&ans , vector<int>&insertionTime, 
    vector<int>&lowestTime , int node , int parent){
        timer++;
        insertionTime[node] = timer;
        lowestTime[node] = timer;

        visited[node] = 1;

        for(auto it : adj[node]){
            if(!visited[it]){
                solve(adj, visited, ans , insertionTime , lowestTime , it , node);
                if(lowestTime[it] > insertionTime[node]){
                    ans.push_back({node , it});
                }

                lowestTime[node] = min(lowestTime[node] , lowestTime[it]);
            }
            else if(visited[it] && parent != it){
                lowestTime[node] = min(lowestTime[node] , lowestTime[it]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& arr) {
        vector<int>adj[n];
        for(auto it : arr){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>ans;

        vector<int>visited(n,0);
        vector<int>insertionTime(n , 0);
        vector<int>lowestTime(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                solve(adj, visited , ans,  insertionTime , lowestTime, i , -1);
            }
        }


        return ans;


    }
};