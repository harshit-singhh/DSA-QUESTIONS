class Solution {
    private:
    int total(int n,vector<int>&dp){
        if(n< 0) return 0;
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = total(n-1 , dp) + total(n-2 , dp);

        return dp[n];

    }
public:
    int climbStairs(int n) {

        vector<int>dp(n+1, -1);
        // int count = 0;
        int totalWays = total(n,dp);
        return totalWays;
    }
};