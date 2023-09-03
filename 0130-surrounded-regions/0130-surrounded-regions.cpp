class Solution {
    void dfs(vector<vector<int>>&visited,  vector<vector<char>> mat , int col , int row){
        int r = mat.size();
        int c = mat[0].size();
        visited[row][col] = 1;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        
        for(int i = 0 ; i < 4 ; i ++){
            int newrow = row + drow[i];
            int newcol = col + dcol[i];
            if(newrow >= 0 && newrow < r && newcol >= 0 && newcol < c && visited[newrow][newcol] == 0 
            && mat[newrow][newcol] == 'O'){
                dfs(visited,mat,newcol , newrow);
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        // for upper and lower row
        for(int i = 0 ; i<m ; i++){
            // upper row
            if(mat[0][i] == 'O' && visited[0][i] == 0){
                dfs(visited,mat,i,0);
            }
            
            // lower row
            if(mat[n-1][i] == 'O' && !visited[n-1][i]){
                dfs(visited,mat,i,n-1);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            //left col
            if(mat[i][0] == 'O' && !visited[i][0]){
                dfs(visited,mat,0,i);
            }
            // right col
            if(mat[i][m-1] == 'O' && visited[i][m-1] == 0 ){
                dfs(visited,mat,m-1,i);
            }
            
        }
        
     
       
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'O' && visited[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        
  
    
    }
};