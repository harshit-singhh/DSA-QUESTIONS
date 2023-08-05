class Solution {
public:
    int countSubstrings(string S) {
    
    int N = S.size();
    vector<vector<bool>>dp(N , vector<bool>(N , false));
    
    int count = 0;
    for(int i = 0 ; i < N ; i++){
        dp[i][i] = true;
        count++;
    }
    
    for(int gap = 1; gap < N ; gap++){
        for(int i = 0 , j = i+gap ; j < N ; i++ , j++){
             
             if(gap == 1){
                 if(S[i] == S[j]){
                     dp[i][j] = true;
                     count++;
                 }
                else dp[i][j] = false;
             }
             else{
                 if(S[i] == S[j] && dp[i+1][j-1] == true){
                     dp[i][j] = true;
                     count++;
                 }
                else dp[i][j] = false;
             }
        }
    }

    return count;
    }
};