class Solution {
     int solve(vector<int>&prices , int index , int canbuy , int fee , vector<vector<int>>&dp){

        if(index == prices.size()){
            return 0; // no more profit can be made
        }

        if(dp[index][canbuy] != -1) return dp[index][canbuy];

        int profit = 0;

        if(canbuy){
            int buy =  -prices[index] + solve(prices , index+1 , 0 , fee ,dp);
            int notbuy = 0 + solve(prices , index+1 , 1 , fee,dp);

            profit = max(buy , notbuy);
        }
        else{
            int sell = (prices[index] - fee) + solve(prices , index+1 , 1 , fee ,dp);
            int notsell = 0 + solve(prices , index+1 , 0 , fee,dp);

            profit = max(sell , notsell);
        }

        return dp[index][canbuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
         int canbuy = 1;

        vector<vector<int>>dp(prices.size() , vector<int>(2 , -1));

        return solve(prices , 0 , canbuy , fee, dp);
    }
};