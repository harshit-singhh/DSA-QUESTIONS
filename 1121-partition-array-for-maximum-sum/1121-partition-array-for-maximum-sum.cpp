class Solution {
    int solve(vector<int>&arr, int i ,int n , int k ,vector<int>&dp){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int maxelement = INT_MIN;
        int maxprofit = 0;
        int profit = 0;
        for(int j = i ; j<min(i+k , n)  ; j++ ){
            maxelement = max(maxelement , arr[j]);
            profit = (j-i+1)*maxelement + solve(arr, j+1 , n,k ,dp);
            maxprofit = max(maxprofit , profit);

        }
        return dp[i] = maxprofit;
    }

    int solvetab(vector<int>&arr, int n , int k){
        vector<int>dp(n+1 , 0);

        for(int i = n-1 ; i >= 0 ; i--){
            int maxelement = INT_MIN;
            int maxprofit = 0;
            int profit = 0;
             for(int j = i ; j<min(i+k , n)  ; j++ ){
                maxelement = max(maxelement , arr[j]);
                profit = (j-i+1)*maxelement + dp[j+1];
                maxprofit = max(maxprofit , profit);

            }
            dp[i] = maxprofit;
        }
        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1 , -1);
        // return solve(arr , 0 , n ,k ,dp);
        return solvetab(arr, n , k);
    }
};