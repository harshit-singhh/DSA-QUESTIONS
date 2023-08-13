class Solution {
    bool solve(vector<int>&nums , int index , vector<int>&dp){
        if(index < 0) return true;

        if(dp[index] != -1) return dp[index];

        if(index - 1 >= 0 && nums[index] == nums[index - 1]){
            if(solve(nums , index-2 ,dp)) return dp[index] = true;

            if(index - 2 >= 0 && nums[index] == nums[index -2]){
                if(solve(nums, index-3 ,dp)) return dp[index] = true;
            }
        }

        if(index - 2 >= 0 && nums[index] - nums[index-1] == 1 && nums[index-1] - nums[index-2] == 1){
            if(solve(nums, index-3 ,dp))return dp[index] = true;
        }
        return dp[index] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1 , -1);
        return solve(nums , n-1 ,dp);
    }
};