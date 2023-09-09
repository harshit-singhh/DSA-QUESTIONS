class Solution {
    private:

    void solve(vector<int>adj[] , vector<vector<int>>&ans , int&timer , vector<int>&TimeToReach , 
    vector<int>&lowestTime , vector<int>&visited , int node , int parent){
        visited[node] = 1;
        TimeToReach[node] = lowestTime[node] = timer;
        timer++;

        for(auto it: adj[node]){
            if(it == parent) continue;
            if(visited[it] == 0){
                solve(adj , ans , timer , TimeToReach , lowestTime , visited, it , node);

                lowestTime[node] = min(lowestTime[node] , lowestTime[it]);
                if(lowestTime[it] > TimeToReach[node]){
                    ans.push_back({node , it});
                }
            }
            else{

                lowestTime[node] = min(lowestTime[node] , lowestTime[it] );
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int timer = 1;

        vector<int>adj[n];

        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>TimeToReach(n);
        vector<int>lowestTime(n);
        vector<int>visited(n , 0);
        vector<vector<int>>ans;
        solve(adj , ans , timer , TimeToReach , lowestTime , visited , 0 , -1);

        return ans;
    }
};