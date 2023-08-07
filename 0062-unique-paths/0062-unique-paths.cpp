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

    // tabulation

    int solve(int m , int n ){
        vector<vector<int>>dp(m , vector<int>(n+1 , -1));

        dp[0][0] = 1;

        for(int row = 0 ; row< m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(row == 0 && col == 0 )continue;
                int ways1 = 0;
                if(row -1 >= 0)
                ways1 = dp[row -1][col];
                
                int ways2 = 0;
                if(col - 1 >= 0)
                ways2 = dp[row][col-1];
                
                dp[row][col] = (ways1 + ways2);
            }
        }

        return dp[m-1][n-1];
    }
public:
    int uniquePaths(int m, int n) {
        
        
        vector<vector<int>>dp(m , vector<int>(n , -1));
        // return solve(m-1 , n-1 , dp);
        return solve(m , n);
    }
};