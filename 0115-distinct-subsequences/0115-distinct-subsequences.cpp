class Solution {
    private:
    int solve(string&s1 , string& s2 , int i , int j , vector<vector<int>>&dp){
        if(j < 0 )return 1;
        if(i < 0 ) return 0;

        if(dp[i][j] != -1 ) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = (solve(s1 , s2 , i-1, j-1 ,dp) + solve(s1 ,s2 , i-1 , j ,dp));

        }
        return dp[i][j] = solve(s1 ,s2 , i-1 , j ,dp);
    }


    //tabulation

    int solvetab(string s1 ,string s2 , int n ,int m){
        vector<vector<double>>dp(n+1 , vector<double>(m+1 , -1));
        for(int i = 0 ; i <= m ; i++){
            dp[0][i] = 0;
        }
        for(int i = 0 ; i <= n ;i++){
            dp[i][0] = 1;
        }


        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<= m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

                }
                else dp[i][j] = dp[i-1][j];  
            }
        }

        return (int)dp[n][m];
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // return solve(s, t , n-1 , m-1 ,dp);
        return solvetab(s, t , n , m);
    }
};