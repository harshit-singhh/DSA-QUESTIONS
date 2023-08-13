class Solution {
    private:
    bool ispossible(int row , int col , vector<vector<int>>&board , int n){
       // Check for previous rows
        int x = row;
        int y = col;
        while (y >= 0) {
            if (board[x][y] == 1) {
                return false;
            }
            y--;
        }

        // Check for upper diagonal
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 1) {
            return false;
            }
            x--;
            y--;
        }

        // Check for lower diagonal
        x = row;
        y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 1) {
            return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(vector<vector<int>>matrix , int n , int&count , int col){
         if (col >= n) {
            // count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (ispossible(row, col, matrix, n)) {
                if(col == n-1) count++;
                matrix[row][col] = 1;
                solve(matrix, n, count, col + 1);
                matrix[row][col] = 0;
            }
        }
        


    }
public:
    int totalNQueens(int n) {
        vector<vector<int>>matrix(n , vector<int>(n , 0));

        int count = 0;
        solve(matrix , n , count, 0);
        return count;
    }
};