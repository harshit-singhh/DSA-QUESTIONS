class Solution {
    private:
    
    int solve(vector<int>&nums , int n , int index , int prev ,vector<vector<int>>&dp){
        if(index == n){
            return 0;
        }

        if(dp[index][prev+1] != -1) return dp[index][prev+1];

        int notpick = 0 + solve(nums , n , index+1 , prev ,dp);
        int pick = 0;
        if(prev == -1 || nums[index] > nums[prev]){
            pick = 1 + solve(nums , n , index+1 , index ,dp);
        }

        return dp[index][prev+1] = max(pick , notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        
        return solve(nums , n , 0 , -1 ,dp);
    }
};