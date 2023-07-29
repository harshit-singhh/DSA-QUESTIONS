class Solution {
    private:
    int solve(vector<int>&arr, int ind,vector<int>&dp){
        if(ind == 0) return arr[0];
        if(ind < 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        int take = arr[ind] + solve(arr, ind-2,dp);
        int notTake = 0 + solve(arr,ind -1,dp);
        
        return dp[ind] = max(take , notTake);
    }
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return solve(arr,n-1,dp);
    }
};