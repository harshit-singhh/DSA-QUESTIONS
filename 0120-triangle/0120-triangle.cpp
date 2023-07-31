class Solution {
    private:
    int solve(vector<vector<int>>&triangle , int row , int col , int maxrow , vector<vector<int>>&dp){
        
        if(row > maxrow || row < 0) return 1e9; // we can return 0 also
        
        if(row == maxrow) return triangle[row][col];
        
        if(dp[row][col] != -1) return dp[row][col];
        
        
        int sum1 = triangle[row][col] + solve(triangle , row+1 , col , maxrow ,dp);
        int sum2 = triangle[row][col] + solve(triangle , row+1 , col+1 , maxrow  ,dp);
        
        return dp[row][col] = min(sum1, sum2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        
        return solve(triangle,0,0, n-1 , dp);
    }
};