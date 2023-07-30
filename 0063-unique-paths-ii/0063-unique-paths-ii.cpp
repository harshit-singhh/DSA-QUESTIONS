class Solution
{

    /*
        Memoization :
        Time Complexity : O(m*n)
        Space Complexity : O((n-1)+(m-1)) + O(m*n)
    */

private:
    int m, n;
    int mod = 2e9+7;

    int helper(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] == 2)
            return 0;
        
        if(obstacleGrid[i][j] == 1) return dp[i][j] = 0;
        
        if (i == 0 && j == 0)
            return dp[i][j] = 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        obstacleGrid[i][j] = 2;
        int up = helper(i - 1, j, obstacleGrid, dp);
        int left = helper(i, j - 1, obstacleGrid, dp);
        obstacleGrid[i][j] = 0;

        return dp[i][j] = (left + up)%mod;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        helper(m - 1, n - 1, obstacleGrid, dp);

        return dp[m - 1][n - 1];
    }
};