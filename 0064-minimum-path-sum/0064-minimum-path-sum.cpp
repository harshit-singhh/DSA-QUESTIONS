class Solution {
    private:
     int solve(vector<vector<int>>&matrix ,int row , int col , int maxrow , int maxcol, vector<vector<int>>&dp){
        if(row > maxrow || col > maxcol || row < 0 || col < 0) return 1e9;
        
        if(row == maxrow && col == maxcol) return matrix[row][col];
        
        
        if(dp[row][col] != -1) return dp[row][col];
        
        
        int sum1 = matrix[row][col] + solve(matrix , row + 1 , col , maxrow , maxcol,dp);
        int sum2 = matrix[row][col] + solve(matrix, row  , col + 1 , maxrow, maxcol,dp);
        
        
        
        return dp[row][col] =  min(sum1 , sum2);
        
    }
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int C = matrix[0].size();
        // int mini = INT_MAX;

        vector<vector<int>>dp(N , vector<int>(C , -1));
 
        return solve(matrix , 0, 0 , N-1 , C-1 , dp);
        
        
        
        
    }
};