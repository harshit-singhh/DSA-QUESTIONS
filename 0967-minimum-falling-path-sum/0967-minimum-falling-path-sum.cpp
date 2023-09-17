class Solution {
    private:

    

    int solve( vector<vector<int>>&matrix , int row , int col , int maxrow , int maxcol, vector<vector<int>>&dp){
        if(row < 0 || row > maxrow || col < 0 || col > maxcol) return 1e9;

        if(row == maxrow && col <= maxcol && col >= 0){
            return matrix[row][col];
        }

        if(dp[row][col] != INT_MAX) return dp[row][col];

        int sum1 = matrix[row][col] + solve(matrix , row +1 , col -1 , maxrow, maxcol , dp);
        int sum2 = matrix[row][col] + solve(matrix , row + 1 , col , maxrow, maxcol , dp);
        int sum3 = matrix[row][col] + solve( matrix , row + 1, col + 1 , maxrow , maxcol , dp);

        return dp[row][col] = min(sum1 , min(sum2 , sum3));
    }

    // tabulation

    int solvetab(vector<vector<int>>&matrix , int r , int c){
        vector<vector<int>>dp(r, vector<int>(c , 1e9));

        for(int i = 0 ; i < c; i++){
            dp[r-1][i] = matrix[r-1][i];
        }

        for(int row = r-2 ; row >= 0 ; row --){
            for(int col = 0 ;  col < c ; col ++){
                int sum1 = matrix[row][col];
                if(row+1 < r && col-1 >= 0) sum1+= dp[row+1][col-1];
                else sum1 = 1e9;
                int sum2 = matrix[row][col];
                if(row+1 < r ) sum2 += dp[row+1][col];
                else sum2 = 1e9;
                int sum3 = matrix[row][col];
                if(row+1 < r && col+1 < c) sum3+= dp[row+1][col+1];
                else sum3 = 1e9;

                dp[row][col] = min(sum1 , min(sum2 , sum3));
            }
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < c ; i++){
            mini = min(mini , dp[0][i]);
        }

        return mini;

    }



    // space optimization

    int space(vector<vector<int>>&matrix , int r , int c){

        vector<int>down(c , 0);
        vector<int>curr(c, 0);

        for(int i = 0 ; i < c ; i++){
            down[i] = matrix[r-1][i];
        }

        for(int row = r-2 ; row >= 0 ; row --){
            
            for(int col = 0 ;  col < c ; col ++){
                int sum1 = matrix[row][col];
                if(row+1 < r && col-1 >= 0) sum1+= down[col-1];
                else sum1 = 1e9;
                int sum2 = matrix[row][col];
                if(row+1 < r ) sum2 += down[col];
                else sum2 = 1e9;
                int sum3 = matrix[row][col];
                if(row+1 < r && col+1 < c) sum3+= down[col+1];
                else sum3 = 1e9;

                curr[col] = min(sum1 , min(sum2 , sum3));
            }

            down = curr;
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < c ; i++){
            mini = min(mini , down[i]);
        }

        return mini;

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n , vector<int>(m , INT_MAX));

        int mini = INT_MAX;

        // for(int i = 0 ; i < m ; i++){
        //     mini = min(mini , solve(matrix, 0, i , n-1 , m-1 , dp));
        // }

        // return mini;

        // return solvetab(matrix , n , m);

        return space(matrix , n , m);
    }
};


// class Solution {
// public:
//     int solve(int row, int col, vector<vector<int>> &matrix,vector<vector<int>> &dp)
//     {
//         if(col<0 || col>matrix[0].size()-1) return 1E9;
//         if(row==0) return matrix[row][col];
//         if(dp[row][col] != INT_MAX) return dp[row][col];
//         int up = matrix[row][col] + solve(row-1,col,matrix,dp);
//         int leftDiagonal = matrix[row][col] + solve(row-1,col-1,matrix,dp);
//         int rightDiagonal = matrix[row][col] + solve(row-1,col+1,matrix,dp);
//         return dp[row][col] = min(up,min(leftDiagonal,rightDiagonal));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int ans = INT_MAX;
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
//         for(int i=0;i<m;i++)
//         {
//             ans = min(ans,solve(n-1,i,matrix,dp));
//         }
//         return ans;
//     }
// };