class Solution {
    int dp[60];
    int solve(int n , int original ){
        if(n < 0 ) return 0;
        if(n == 1) return 1;
        if(n == 0) return 1;


        if(dp[n] != -1) return dp[n];

        int multiply = 1;
        for(int i = 1 ; i != original && i<= n ; i++){

            int total = i*solve(n-i, original);
            multiply = max(multiply , total);
        }

        return dp[n] = multiply;
    }
public:
    int integerBreak(int n) {
        memset(dp , -1 , sizeof(dp));
        return solve(n , n);
    }
};