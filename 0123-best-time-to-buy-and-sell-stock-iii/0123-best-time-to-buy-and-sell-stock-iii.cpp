class Solution {
     int solve(vector<int>&prices , int index , int canbuy ,int count ,  vector<vector<vector<int>>>&dp){
         if(count > 4){
             return 0;
         }
        if(index == prices.size()){
            return 0; // no more profit can be made
        }

        if(dp[index][canbuy][count] != -1) return dp[index][canbuy][count];

        int profit = 0;

        if(canbuy){
            int buy =  -prices[index] + solve(prices , index+1 , 0 , count+1 , dp);
            int notbuy = 0 + solve(prices , index+1 , 1 ,count , dp);

            profit = max(buy , notbuy);
        }
        else{
            int sell = prices[index] + solve(prices , index+1 , 1 , count + 1, dp);
            int notsell = 0 + solve(prices , index+1 , 0 ,count , dp);

            profit = max(sell , notsell);
        }

        return dp[index][canbuy][count] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int canbuy = 1;

        vector<vector<vector<int>>>dp(prices.size()+1 , vector<vector<int>>(2 , vector<int>(5 , -1)));

        int count = 0;
        return solve(prices , 0 , canbuy , count , dp);
    }
};