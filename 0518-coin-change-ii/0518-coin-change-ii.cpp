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

    //tabulation
    int solvetab(vector<int>&coins , int target , int n){
        vector<vector<int>>dp(n+1 , vector<int>(target+1 , -1));

        for(int i = 0 ; i <= target ; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
            else dp[0][i] = 0;
        }

        for(int index = 1 ; index < n ; index++){
            for(int amount = 0 ; amount <= target ; amount++){

                int notpick = dp[index-1][amount];
                int pick = 0;
                if(amount - coins[index] >= 0){
                    pick = dp[index][amount - coins[index]];
                }

                dp[index][amount] = pick + notpick;
            }
        }

        return dp[n-1][target];
    }


    int space(vector<int>&coins , int target , int n){
        vector<int>prev(target+1 , 0);
        vector<int>curr(target+1 , 0);

        for(int i = 0 ; i <= target ; i++){
            if(i % coins[0] == 0){
                prev[i] = 1;
            }
            else prev[i] = 0;
        }

        for(int index = 1 ; index < n ; index++){
            for(int amount = 0 ; amount <= target ; amount++){

                int notpick = prev[amount];
                int pick = 0;
                if(amount - coins[index] >= 0){
                    pick = curr[amount - coins[index]];
                }

                curr[amount] = pick + notpick;
            }
            prev = curr;
        }

        return prev[target];
    
    }



public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n+1 , vector<int>(amount+1 , -1));
        // return solve(coins , amount , n-1 ,dp);
        // return solvetab(coins , amount , n);
         return space(coins , amount , n);
    }
};