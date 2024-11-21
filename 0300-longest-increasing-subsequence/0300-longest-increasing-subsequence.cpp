class Solution {
public:
    int dp[2505][2505];
    int solve(vector<int>&nums, int index ,int n , int prevIndex){
        if(index == n ) return 0;
        
        if(dp[index+1][prevIndex+1] != -1) return dp[index+1][prevIndex+1];

        int pick = 0 , notpick = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            pick = 1 + solve(nums, index+1 , n , index);
            notpick = 0 + solve(nums , index+1 , n , prevIndex);
        }
        else{
            notpick = 0+ solve(nums , index+1 , n , prevIndex);
        }

        return dp[index+1][prevIndex+1] = max(pick , notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prevElemIndex = -1;
        memset(dp , -1 , sizeof(dp));
        return solve(nums, 0 , n , prevElemIndex);
    }
};