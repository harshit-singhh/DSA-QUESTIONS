#define P pair<int,int>

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        if(n == 1 || n == 0 ) return 0;

        queue<P>q; // {node , mask}
        set<P>visited; // {node , pathMask}

        // BFS from all nodes

        for(int i = 0 ; i < n ; i++){
            
            int maskValue = (1 << i);

            q.push({i , maskValue});

            visited.insert({i , maskValue});
        }

        // if all nodes will be visited , then our mask will look like this 1111 , and value of this 
        // will be 2^n - 1;

        int allVisitedState = pow(2 , n) - 1;

        int path = 0;

        while(!q.empty()){
            int size = q.size();

            path++;
            
            for(int i = 0 ; i < size ;  i++){
                auto curr = q.front();
                q.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for(auto &adj : graph[currNode]){
                    int nextMask = currMask | (1 << adj);

                    if(nextMask == allVisitedState){
                        return path;
                    }

                    if(visited.find({adj , nextMask}) == visited.end()){
                        visited.insert({adj , nextMask});
                        q.push({adj , nextMask});
                    }


                }
            }
        }

        return -1;
        
    }
};