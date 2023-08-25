class Solution {
    bool solve(string s1 , int i , int n , string s2 , int j , int m , string s3 , string temp ,  vector<vector<int>>&dp){
        if(i == n && j == m){
            if(temp == s3) return true;
            else return false;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool first = false;
        bool second = false;
       if (i < s1.size() && s1[i] == s3[i + j]) {
            first = solve(s1, i + 1, n , s2, j, m , s3, temp + s1[i], dp);
        }
        if (j < s2.size() && s2[j] == s3[i + j]) {
            second = solve(s1, i, n , s2, j + 1,m, s3, temp + s2[j], dp);
        }

        return dp[i][j] = (first || second);
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        string temp;
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return solve(s1 , 0 , n ,s2, 0 , m , s3 , temp ,dp);
    }
};