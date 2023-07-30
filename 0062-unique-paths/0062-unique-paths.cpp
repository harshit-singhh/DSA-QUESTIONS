class Solution {
    private:
     int solve(int row , int col , int maxrow , int maxcol , vector<vector<int>>&dp){
        if(row == maxrow && col == maxcol){
            
            return 1;
        }
        
        if(row > maxrow || col > maxcol) return 0;
        
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int ways1 = solve(row , col+1 , maxrow , maxcol,dp );
        int ways2 = solve(row+1 , col , maxrow , maxcol,dp );
        
        return dp[row][col] = (ways1 + ways2);
        
        
    }
public:
    int uniquePaths(int m, int n) {
        
        
        vector<vector<int>>dp(m , vector<int>(n , -1));
        return solve(0,0, m-1 , n-1 , dp);
    }
};