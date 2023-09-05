class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int>adj[numCourses];

        for(auto it: pre){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int>indegree(numCourses);

        for(int i = 0 ; i < numCourses ; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;

        for(int i = 0  ; i< numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        vector<int>ans;
        while(!q.empty()){
            int element = q.front();
            q.pop();
            ans.push_back(element);

            for(auto it: adj[element]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }

        }

        if(ans.size() == numCourses) return ans;
        return {};
    }
};