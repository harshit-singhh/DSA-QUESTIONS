class Solution {
    private:

    int solve(string& str1 , string& str2 , int i , int j , vector<vector<int>>&dp){
        if(j < 0) return i+1;
        if(i< 0) return j+1;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j]){
            return dp[i][j] = solve(str1 , str2 , i-1 , j-1 ,dp);
        }
        else{
            return dp[i][j] = 1+ min(solve(str1 , str2 , i , j-1 ,dp) , 
                        min(solve(str1 ,str2 , i-1 , j-1 ,dp) , 
                            solve(str1 , str2 , i-1 , j ,dp)));
        }
    }


    // tabulation

    int solvetab(string str1 , string str2 , int n , int m){
        vector<vector<int>>dp(n+1 , vector<int>(m+1, -1));
        for(int i = 0 ; i<= n ; i++){
            dp[i][0] = i+1;
        }

        for(int i = 0 ; i<= m ; i++){
            dp[0][i] = i+1;
        }

        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<= m ; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j-1] , min(dp[i-1][j-1] , dp[i-1][j]));
                }
            }
        }

        return dp[n][m]-1;
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1, -1));
        // return solve(word1 , word2 , n-1 , m-1 ,dp);
        return solvetab(word1 , word2 , n , m );
    }
};