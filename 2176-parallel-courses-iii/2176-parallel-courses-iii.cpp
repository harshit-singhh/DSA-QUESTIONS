class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indegree(n , 0);

        vector<int>adj[n];

        for(auto it : relations){
            int u = it[0]-1;
            int v = it[1]-1;

            indegree[v]++;

            adj[u].push_back(v);

        }

        queue<int>q;
        vector<int>distance(n,0);

        // for(int i = 0 ; i < n ; i++) distance[i] = time[i];

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0 ){
                q.push(i);

                distance[i] = time[i];
                
            }
        }


        

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(indegree[it] != 0){
                    indegree[it]--;
                    if(indegree[it] == 0 ) q.push(it);
                    distance[it] = max(distance[node] +  time[it] , distance[it] );
                }
            }
        }

        int maxi = *max_element(distance.begin() , distance.end());

        return maxi;
    }
};