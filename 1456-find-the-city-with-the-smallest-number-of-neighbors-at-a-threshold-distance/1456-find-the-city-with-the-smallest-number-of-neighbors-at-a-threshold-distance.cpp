class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>>dist(n, vector<int>(n , INT_MAX));
        
        // now we will fill out distance matrix
        // this is undirected graph so we did both ways
        for(auto it: edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        
        // from itself to itself it is always zero
        
        for(int i = 0 ; i< n ; i++) dist[i][i] = 0;
        
        // floyd warshal algo
        
        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i< n ;i ++){
                for(int j = 0 ;j < n ; j++){
                    if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                    continue;
                    
                    dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                }
            }
        }
        
        int cntCity = n;
        int cityNo = -1;
        
        // we will again traverse out made matrix, to check everyones adjacent node distance from the 
        // currect node so that pta chale ki kon kon threshhold ke neeche he 
        
        for(int i = 0 ; i < n ; i++){
            int counter = 0;
            for(int j = 0 ;j < n ; j++){
                if(dist[i][j] <= distanceThreshold){
                    counter ++;
                    
                }
            }
            if(counter <= cntCity){
                cntCity = counter;
                cityNo = i;
            }
        }
        
        return cityNo;
    
    }
};