class Solution {
    #define mod 1000000007
    int dp[501][501];
    int solve(int stepsRemaining , int currPos ,  int range ){
        if(stepsRemaining == 0 ){
            if(currPos == 0 ) return 1;
            else return 0;
        }

        if(dp[stepsRemaining][currPos] != -1) return dp[stepsRemaining][currPos];

        long long goleft = 0 , goright = 0 , stayhere = 0;
        if(currPos + 1 <= range){
            goright = solve(stepsRemaining -1 , currPos+1 , range);
        }
        if(currPos - 1 >= 0 ){
            goleft = solve(stepsRemaining -1 , currPos-1 , range);
        }
        
        stayhere = solve(stepsRemaining -1 , currPos , range);


        return dp[stepsRemaining][currPos] = (goleft + goright + stayhere)%mod;
    }
public:
    int numWays(int steps, int arrLen) {
        int range = arrLen;

        if(arrLen > steps){
            range = steps;
        }

        memset(dp , -1 , sizeof(dp));
        return solve(steps , 0 , range-1 );
    }
};