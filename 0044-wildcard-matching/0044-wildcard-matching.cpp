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
public:
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return solve(s , p , n-1 , m-1 ,dp);
    }
};