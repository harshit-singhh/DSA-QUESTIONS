class Solution {
public:
    int solve(vector<int>& cost, vector<int>& time, int i, int k, vector<vector<int>>& dp) {
        // Base case: if there are no more walls to paint (k <= 0), cost is 0.
        if (k <= 0) return 0;
        // Base case: if we run out of walls to consider (i < 0), return a large value.
        if (i < 0) return 1000000000;
        // If this subproblem is already solved, return the cached result.
        if (dp[i][k] != -1) return dp[i][k];

        // Calculate the cost and time for two scenarios: taking the current wall or not taking it.
        int t = time[i];
        int take = cost[i] + solve(cost, time, i - 1, k - t - 1, dp);
        int nottake = solve(cost, time, i - 1, k, dp);

        // Return the minimum cost between taking and not taking the current wall,
        // and store it in the DP table for reuse.
        return dp[i][k] = min(take, nottake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        // Create a DP table with dimensions (time.size() + 1) x (time.size() + 1) and initialize with -1.
        vector<vector<int>> dp(time.size() + 1, vector<int>(time.size() + 1, -1));
        // Start solving the problem by calling the 'solve' function with the rightmost wall and total walls.
        return solve(cost, time, time.size() - 1, time.size(), dp);
    }
};