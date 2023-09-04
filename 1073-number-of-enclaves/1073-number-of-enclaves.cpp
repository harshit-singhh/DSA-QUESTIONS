class Solution {

    private:
    bool isValid(int currRow , int currCol , int row , int col){
        if(currRow >= 0 && currRow < row && currCol >= 0 && currCol < col) return true;
        return false;
    }

    void dfs(vector<vector<int>>& grid , vector<vector<int>>&visited , int currRow, int currCol,
    int row , int col){
        visited[currRow][currCol] = 1;

        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , -1 , 0 , 1};

        for(int i = 0 ; i < 4 ; i++){
            int newrow = currRow + drow[i];
            int newcol = currCol + dcol[i];

            if(isValid(newrow , newcol , row, col) && grid[newrow][newcol] == 1 &&
             visited[newrow][newcol] == 0){
                 dfs(grid , visited , newrow , newcol , row , col);
             }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>visited(row , vector<int>(col , 0));

        // top and bottom row

        for(int i = 0 ; i < col; i++){
            
            if(grid[0][i] == 1 && visited[0][i] == 0){
                dfs(grid, visited , 0 , i , row , col);
            }

            if(grid[row-1][i] == 1 && visited[row-1][i] == 0){
                dfs(grid, visited, row-1 , i , row , col);
            }
        }

        // left and right col

        for(int i = 0 ; i < row ; i++){
            if(grid[i][0] == 1 && visited[i][0] == 0){
                dfs(grid, visited , i , 0 , row , col);
            }

            if(grid[i][col-1] == 1 && visited[i][col-1] == 0){
                dfs(grid , visited , i , col-1 , row , col);
            } 
        }

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }
};