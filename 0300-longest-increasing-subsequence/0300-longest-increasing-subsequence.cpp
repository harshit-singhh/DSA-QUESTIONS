class Solution {
    private:
    
    int solve(vector<int>&nums , int n , int index , int prev ,vector<vector<int>>&dp){
        if(index == n+1){
            return 0;
        }

        if(dp[index][prev] != -1) return dp[index][prev];

        int notpick = 0 + solve(nums , n , index+1 , prev ,dp);
        int pick = 0;
        if(prev == 0 || nums[index-1] > nums[prev-1]){
            pick = 1 + solve(nums , n , index+1 , index ,dp);
        }

        return dp[index][prev] = max(pick , notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        
        return solve(nums , n , 1 , 0 ,dp);
    }
};