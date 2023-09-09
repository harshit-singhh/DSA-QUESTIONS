class Solution {
     private:
    
    bool isvalid(int currRow , int currCol , int row, int col){
        if(currRow >= 0 && currRow < row && currCol >= 0 && currCol < col) return true;
        return false;
    }
    
    
    int dfs(vector<vector<int>>& grid ,vector<vector<int>>&visited , int currRow , int currCol ,
    int row , int col){
        visited[currRow][currCol] = 1;
        int area = 1;
        
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , -1 , 0 , 1};
        
        for(int i = 0 ; i < 4 ; i++){
            int newrow = currRow + drow[i];
            int newcol = currCol + dcol[i];
            
            if(isvalid(newrow, newcol , row, col) && 
            visited[newrow][newcol] == 0 && grid[newrow][newcol ] == 1){
                
                area += dfs(grid , visited, newrow , newcol , row, col);
            }
        }
        
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int maxarea = 0;
        vector<vector<int>>visited(row , vector<int>(col , 0));
        
        for(int i = 0 ; i < row ;  i++){
            for(int j = 0 ; j < col ; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    maxarea = max(maxarea , dfs(grid , visited, i , j , row , col));
                }
            }
        }
        
        return maxarea;
    }
};