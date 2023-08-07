class Solution {
    int solve(vector<int>&prices , int index , int canbuy , vector<vector<int>>&dp){

        if(index == prices.size()){
            return 0; // no more profit can be made
        }

        if(dp[index][canbuy] != -1) return dp[index][canbuy];

        int profit = 0;

        if(canbuy){
            int buy =  -prices[index] + solve(prices , index+1 , 0 ,dp);
            int notbuy = 0 + solve(prices , index+1 , 1 ,dp);

            profit = max(buy , notbuy);
        }
        else{
            int sell = prices[index] + solve(prices , index+1 , 1 ,dp);
            int notsell = 0 + solve(prices , index+1 , 0 ,dp);

            profit = max(sell , notsell);
        }

        return dp[index][canbuy] = profit;
    }

    // tabulation

    int solvetab(vector<int>&prices , int n){
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));

        for(int index = n-1 ; index >= 0 ; index --){
            for(int canbuy = 0 ; canbuy <= 1 ; canbuy ++){
                int profit = 0;
                if(canbuy){
                    int buy =  -prices[index] + dp[index+1][0];
                    int notbuy = 0 + dp[index+1][1];

                    profit = max(buy , notbuy);
                }
                else{
                    int sell = prices[index] + dp[index+1][1];
                    int notsell = 0 + dp[index+1][0];

                    profit = max(sell , notsell);
                }

                dp[index][canbuy] = profit;
            }
        }

        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int canbuy = 1;

        vector<vector<int>>dp(prices.size() , vector<int>(2 , -1));

        // return solve(prices , 0 , canbuy ,dp);
        int n = prices.size();
        return solvetab(prices , n);
    }
};