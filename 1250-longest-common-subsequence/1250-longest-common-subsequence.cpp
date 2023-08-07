class Solution {
     private:
    // int solve( string &s1 , string &s2 , int n , int m ,vector<vector<int>>&dp){
        
    //     if(n == 0) return 0; //instead of n== -1 , we did n== 0 because we shifted the index
    //     if(m == 0) return 0;
        
    //     if(dp[n][m] != -1) return dp[n][m];
        
    //     if(s1[n-1] == s2[m-1]){ // because we have shifted , so we did this insted of s1[n] == s2[m];
    //         return dp[n][m] = 1 + solve(s1 , s2 , n-1 , m-1 ,dp);
    //     }
        
    //     else return dp[n][m] = max(solve(s1 , s2 , n-1 , m ,dp) , solve(s1 ,s2 , n , m-1 ,dp));
    // }


    //tabulation - we shifted the index in this question to perform our tabulation
    // therefore memoization code is also changed a little bit

    int solvetab(string &s1 , string &s2 , int n , int m){
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // now base case is at index 0 , so we can show in dp matrix
        // other wise it was difficult to show -ve index in dp matrix
        
        for(int i = 0 ; i <= m ; i++) dp[0][i] = 0;
        
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;

        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<= m ; j++){
                 if(s1[i-1] == s2[j-1]){ 
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
        
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];

    }


    int space(string s1 , string s2 , int n , int m){

        vector<int>prev(m +1 , 0);
        vector<int>curr(m + 1 , 0);

        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<= m ; j++){
                 if(s1[i-1] == s2[j-1]){ 
                    curr[j] = 1 + prev[j-1];
                }
        
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }

        return prev[m];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // return solve(text1 , text2 , n , m ,dp); // to shift the index . n- 1 = n , m-1 = m

        // return solvetab(text1 , text2 , n , m);
        return space(text1 , text2 , n , m );
    }
};