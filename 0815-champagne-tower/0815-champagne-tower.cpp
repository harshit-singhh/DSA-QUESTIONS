class Solution {
public:
    double champagneTower(int K, int R, int C) {
        vector<vector<double>>dp(101 , vector<double>(101 , 0));
        
        dp[0][0] = K;
        
        for(int i = 0 ; i <= R ; i ++){
            for(int j = 0 ; j <= C ; j++){
                if(dp[i][j] > 1){
                    
                    double toMoveBelow = (dp[i][j] - 1);
                    double forLeftSide = toMoveBelow / 2.0;
                    double forRightSide = forLeftSide;
                    dp[i][j] = 1.0;
                    
                    if(i+1 < K) dp[i+1][j] += forLeftSide;
                    if(i+1 < K && j+1 < K) dp[i+1][j+1] += forLeftSide;
                    
                }
            }
        }

        return dp[R][C];
        
        
    }
};