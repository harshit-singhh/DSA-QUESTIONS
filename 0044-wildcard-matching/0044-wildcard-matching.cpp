class Solution {
    bool solve(string& str1 , string& str2 , int i , int j ,vector<vector<int>>&dp){

        if(j <0 && i >= 0) return false;
        if(j < 0 && i < 0) return true;
        if(i < 0 && j >= 0){
            for(int k = 0 ; k <= j ; k++){
                if(str2[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j] || str2[j] == '?'){
            return dp[i][j] = solve(str1 , str2 , i -1 , j -1,dp);
        }
        else if(str2[j] == '*'){
            return dp[i][j] = (solve(str1 , str2 , i-1 , j-1 ,dp) || solve(str1,str2 , i , j-1 ,dp) || 
            solve(str1 , str2, i-1 , j ,dp));
        }
        else return dp[i][j] = false;
    }


    //tabulation

    bool solvetab(string str1 , string str2 , int n , int m){
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

        for(int i = 1; i<= n ; i++){
            dp[i][0] = false;
        }
        dp[0][0] = true;
        for(int i = 0 ; i< m ; i++){
            if(str2[i] != '*') dp[0][i+1] = false;
            else dp[0][i+1] = true;
        }


        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<= m ; j++){
                if(str1[i-1] == str2[j-1] || str2[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(str2[j-1] == '*'){
                    dp[i][j] = (dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]);
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];

    }


public:
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return solve(s , p , n-1 , m-1 ,dp);
        return solvetab(s , p , n , m);
    }
};