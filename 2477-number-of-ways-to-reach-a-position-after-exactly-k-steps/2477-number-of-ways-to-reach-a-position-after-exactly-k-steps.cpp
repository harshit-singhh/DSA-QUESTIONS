class Solution {
     #define mod 1000000007
    int dp[1001][5000];
    
    int solve(int stepsRemaining , int currPos ,  int toReach ){
        if(stepsRemaining == 0 ){
            if(currPos == toReach ) return 1;
            else return 0;
        }

        if(dp[stepsRemaining][currPos+1000] != -1) return dp[stepsRemaining][currPos+1000];

        long long goleft = 0 , goright = 0;
        
        goright = solve(stepsRemaining -1 , currPos+1 , toReach);
        
        
        goleft = solve(stepsRemaining -1 , currPos-1 , toReach);


        return dp[stepsRemaining][currPos+1000] = (goleft + goright)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {

        memset(dp , -1 , sizeof(dp));

        return solve(k , startPos , endPos );
    }
};