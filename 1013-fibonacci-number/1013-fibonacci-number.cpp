#define mod 1000000007
class Solution {
    int solve(int n ,vector<int>&dp){
        if(n == 0 || n == 1){
            return n;
        }
        
        if(dp[n] != -1) return dp[n];
        
        int num = solve(n-2 ,dp) + solve(n-1 ,dp);
        
        return dp[n] = num%mod;
    }
public:
    int fib(int n) {
        vector<int>dp(n+1 , -1);
        return solve(n ,dp);
    }
};