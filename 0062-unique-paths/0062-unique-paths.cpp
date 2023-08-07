class Solution {
    private:
     int solve(int row , int col ,vector<vector<int>>&dp){
        
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int ways1 = solve(row -1, col, dp );
        int ways2 = solve(row , col-1 ,dp );
        
        return dp[row][col] = (ways1 + ways2);
        
        
    }
public:
    int uniquePaths(int m, int n) {
        
        
        vector<vector<int>>dp(m , vector<int>(n , -1));
        return solve(m-1 , n-1 , dp);
    }
};