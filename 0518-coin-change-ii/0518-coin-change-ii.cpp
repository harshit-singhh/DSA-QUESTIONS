class Solution {
    int solve(vector<int>&coins , int amount , int index , vector<vector<int>>&dp){

        if(index == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            return 0;
        }

        if(dp[index][amount] != -1) return dp[index][amount];
        int notpick = solve(coins , amount , index-1, dp);
        int pick = 0;
        if(amount - coins[index] >= 0){
            pick = solve(coins , amount - coins[index] , index ,dp);
        }

        return dp[index][amount] = pick + notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n+1 , vector<int>(amount+1 , -1));
        return solve(coins , amount , n-1 ,dp);
    }
};