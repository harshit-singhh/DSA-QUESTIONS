class Solution {
public:
    vector<int> getRow(int n) {
        

        vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , 0));

        dp[0][0] = 1;

        for(int i = 1 ; i < n +1 ; i++){
            for(int j = 0 ; j < n + 1 ; j++){
                int sum = 0;

                sum += dp[i-1][j];
                if(j-1 >= 0 ) sum += dp[i-1][j-1];

                dp[i][j] = sum;
            }
        }

        return dp[n];
    }
};