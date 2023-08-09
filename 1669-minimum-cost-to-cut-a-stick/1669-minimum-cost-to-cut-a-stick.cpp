class Solution {
    private:
    int solve(int i , int j , vector<int>cuts , vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;

        for(int index = i ; index <= j ; index ++){
            int total = cuts[j+1] - cuts[i-1] + solve(i , index-1 , cuts , dp) + solve(index+1 , j , cuts , dp);
            mini = min(total , mini);
        }
        return dp[i][j] = mini;
    }

    // tabulation

    int solvetab(vector<int>cuts , int len){
        vector<vector<int>>dp(len , vector<int>(len , 0));
     
        for(int i = len-2 ; i>= 1 ; i--){
            for(int j = i ; j <= len-2 ; j++){
                if(i > j )continue;
                int mini = 1e9;
                for(int index = i ; index <= j ; index++){

                    int total = cuts[j+1] - cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                    mini = min(total , mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][len-2];
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin() , cuts.end());


        int len = cuts.size();
        vector<vector<int>>dp(len+1 , vector<int>(len+1 , -1));


        // return solve(1 , len-2 , cuts, dp);
        return solvetab(cuts , len);
    }
};