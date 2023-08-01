class Solution {
    int solve(vector<int>&coins , int n , int amount , int index , int sum ,vector<vector<int>>&dp){
        if(sum == amount) return 1;
        if(sum > amount) return 0;
        if(index == n){
            if(sum == amount) return 1;
            return 0;
        }

        if(dp[index][sum] != INT_MIN) return dp[index][sum];
        int pick = solve(coins , n , amount , index, sum + coins[index] ,dp);
        int notpick = solve(coins , n , amount , index + 1, sum,dp );

        return dp[index][sum] = pick + notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        int n = coins.size();

        vector<vector<int>>dp(n+1 , vector<int>(amount+1, INT_MIN));
        return solve(coins ,n , amount , 0 , 0 ,dp);
    }
};