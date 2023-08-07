class Solution {
    private:
    int solve(vector<int>&prices , int index , int n ,int canbuy , int cd ,vector<vector<vector<int>>>&dp){
        if(index == n){
            return 0;
        }

        if(dp[index][canbuy][cd] != -1) return dp[index][canbuy][cd];

        int profit = 0;
        if(canbuy){
            int buy = 0;
            if(cd == 0){
                buy = -prices[index] + solve(prices , index+1 , n , 0 , cd ,dp);
            }
            int notbuy = 0 + solve(prices , index+1 , n , 1 , 0 ,dp);

            profit = max(buy , notbuy);
        }
        else{
            int sell = prices[index] + solve(prices , index+1 ,n ,1 ,1 ,dp);
            int notsell = 0+ solve(prices , index+1 , n , 0 , 0 ,dp);

            profit = max(sell , notsell);
        }

        return dp[index][canbuy][cd] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>>dp(n+2 , vector<vector<int>>(2 , vector<int>(2 , -1)));

        return solve(prices , 0  , n  ,1, 0 ,dp);
    }
};