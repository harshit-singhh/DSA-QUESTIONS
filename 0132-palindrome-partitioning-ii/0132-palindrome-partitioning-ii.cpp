class Solution {
    bool isPalindrome(int low , int high , string &temp){
       

        while(low <= high){
            if(temp[low] != temp[high]) return false;
            low++;
            high--;
        }
        return true;
    }


    int solve(string &s , int i , int n , vector<int>&dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        string temp = "";
        
        int mini = 1e9;
        for(int j = i ; j < n ; j++){
            int count = 0;
            
            if(isPalindrome(i , j , s)){
                count = 1 + solve(s , j+1 , n ,dp);
                mini = min(mini , count);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        vector<int>dp(s.size() +1 , -1);
        return solve( s, 0 , s.size() ,dp) -1;
    }
};