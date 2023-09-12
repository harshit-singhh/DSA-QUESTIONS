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

    int solvetab(vector<int>&arr, int n ){
        vector<int>dp(n , 0);

        dp[0] = arr[0];
        for(int ind = 1 ; ind< n ; ind++){
            int take = arr[ind];
            if(ind - 2 >= 0) take+= dp[ind-2];
            int notTake = 0 + dp[ind-1];
            
            dp[ind] = max(take , notTake);
        }

        return dp[n-1];
    }

    int space(vector<int>&arr, int n){
        int curr;
        int prev = arr[0];
        int prev2 = 0;

        for(int ind = 1 ; ind < n ; ind++){
            int take = arr[ind];
            if(ind - 2 >= 0) take+= prev2;
            int notTake = 0 + prev;
            
            curr = max(take , notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;

    }
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        // return solve(arr,n-1,dp);
        // return solvetab(arr , n);

        return space(arr , n);

    }
};