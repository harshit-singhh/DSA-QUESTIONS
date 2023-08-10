class Solution {


    vector<vector<int>>table(string s , int n){
        vector<vector<int>>dp(n , vector<int>(n , 0));
        for(int i = 0 ; i < n ; i++) dp[i][i] = 1;

        for(int gap = 1 ; gap < n ; gap++){
            for(int i = 0 , j = i+gap ; j<n ; i++ , j++){
                if(gap == 1){
                    if(s[i] == s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        return dp;
    }


    // bool isPalindrome(int low , int high , string &temp){
       

    //     while(low <= high){
    //         if(temp[low] != temp[high]) return false;
    //         low++;
    //         high--;
    //     }
    //     return true;
    // }


    int solve(string &s , int i , int n , vector<int>&dp , vector<vector<int>>&PalindromeTable){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = 1e9;
        for(int j = i ; j < n ; j++){
            int count = 0;
            
            if(PalindromeTable[i][j] == 1){
                count = 1 + solve(s , j+1 , n ,dp ,PalindromeTable);
                mini = min(mini , count);
            }
        }
        return dp[i] = mini;
    }


    // tabulation

    int solvetab(string s , int n , vector<vector<bool>>&PalindromeTable){
        vector<int>dp(s.size() +1 , 0);

        for(int i = n-1 ; i >= 0 ; i--){
            int mini = 1e9;
            for(int j = i ; j < n ; j++){
                int count = 0;
                
                if(PalindromeTable[i][j] == 1){
                    count = 1 + dp[j+1];
                    mini = min(mini , count);
                }
            }
            dp[i] = mini;
        }
        return dp[0];
    }
public:
    int minCut(string s) {
        vector<int>dp(s.size() +1 , -1);
        int n = s.size();
        vector<vector<int>>PalindromeTable = table(s , n);
        return solve( s, 0 , s.size() ,dp ,PalindromeTable) -1;

        // return solvetab(s, s.size() , PalindromeTable)-1;
    }
};