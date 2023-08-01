class Solution {
    private:
    int solve(vector<int>&coins , int m , int v , int index  , vector<vector<int>>&dp){
        if(v < 0) return 1e8;
        if(v == 0) return 0;
        if(index == m) return 1e8;
        
        if(dp[index][v] != -1) return dp[index][v];
        
        int pick = 1 + solve(coins , m , v - coins[index] ,index, dp);
        int notpick = 0 + solve(coins, m , v ,index + 1 ,dp);
        
        return dp[index][v] = min(pick , notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int M = coins.size();
        vector<vector<int>>dp(M + 1 , vector<int>(amount +1 , -1));

	    
	    int ans = solve(coins , M , amount , 0  ,dp);
	    if(ans == 1e8) return -1;
	    else return ans;
    }
};