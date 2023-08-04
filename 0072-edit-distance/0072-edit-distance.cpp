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
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1, -1));
        return solve(word1 , word2 , n-1 , m-1 ,dp);
    }
};