class Solution {


    int dp[501][501][2];
     int solve(vector<int>&arr , int i , int j , int total , int turn){
        if(i > j ) return 0;

        if(dp[i][j][turn] != -1 )return dp[i][j][turn];
        if(turn){
            int fromFront = arr[i] + solve(arr, i+1 , j , total , 1-turn);
            int fromBehind = arr[j] + solve(arr, i , j-1 , total , 1-turn);

            return dp[i][j][turn] = max(fromFront , fromBehind);
        }
        else{
            int fromFront = solve(arr, i+1 , j , total , 1-turn);
            int fromBehind = solve(arr, i , j-1 , total , 1-turn);

            return dp[i][j][turn] = min(fromFront , fromBehind);
        }
    }
public:
    bool stoneGame(vector<int>& nums) {
         int n = nums.size();

        int i = 0 ;
        int j = n-1;

        memset(dp , -1 , sizeof(dp));

        int total = accumulate(nums.begin() , nums.end() , 0);
        int turn = 1;
        int ans  = solve(nums , i , j , total , turn);

        int player2 = total - ans;
        if(ans >= player2) return true;
        return false;
    }
};