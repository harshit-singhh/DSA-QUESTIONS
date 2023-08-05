class Solution {
    private:
    int solve(int n ,vector<int>&dp){
        
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];
        int count = 0;
        for(int i = 1 ; i<= n ; i++){
            count += solve(i-1 ,dp)*solve(n-i ,dp);
        }

        return dp[n] = count;
    
    }
   
public:
    int numTrees(int n) {
        vector<int>dp(20 , -1);
        return solve(n , dp);
    }
};