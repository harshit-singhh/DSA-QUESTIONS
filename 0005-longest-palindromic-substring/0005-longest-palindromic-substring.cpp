class Solution {
public:
    string longestPalindrome(string S) {
        int n = S.size();
        
        
        vector<vector<int>>dp(n , vector<int>(n , 0));
        
        int maxi = INT_MIN;
        int start = -1;
        int end = -1;
        
        
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 1;
            if(dp[i][i] > maxi){
                maxi = dp[i][i];
                start = i;
                end = i;
            }
        }
        
        
        
        for(int gap = 1 ; gap < n ; gap ++){
            for(int i = 0 , j = i+gap ; j < n ; i++ , j++){
                
                if(gap == 1){
                    if(S[i] == S[j]){
                        dp[i][j] = 2;
                        if(dp[i][j] > maxi){
                            maxi = dp[i][j];
                            start = i;
                            end = j;
                        }
                    }
                    else dp[i][j] = 0; // not necessary to write because all values in dp are already 0.
                }
                
                else{
                     if(S[i] == S[j] && dp[i+1][j-1] != 0){
                         dp[i][j] = 2 + dp[i+1][j-1];
                         if(dp[i][j] > maxi){
                            maxi = dp[i][j];
                            start = i;
                            end = j;
                        }
                     }
                     else dp[i][j] = 0; // not necessary
                }
            }
        }
        
        string ans;
        
        ans = S.substr(start , end - start + 1);
        
        
        return ans;
    }
};