class Solution {
public:
    int dp[30005][2];
    int solve(vector<int>&prices , int index , int n , bool buy){
        if(index == n ){
            return 0;
        }

        if(dp[index][buy] != -1) return dp[index][buy];

        int buyy = 0 , sell = 0;

        if(buy == false){
            int pick = -prices[index] + solve(prices ,index+1 ,  n , true);
            int notpick = solve(prices, index+1 ,  n , false);
            buyy = max(pick , notpick);
        }
        else{
            int sold = prices[index] + solve(prices ,index+1 , n , false);
            int notsold = solve(prices ,index+1 , n , true);;
            sell = max(sold , notsold);
        }

        return dp[index][buy] = max(buyy , sell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        bool buy = false;
        memset(dp , -1 , sizeof(dp));
        return solve(prices , 0 , n , buy);
        
    }
};