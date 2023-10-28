class Solution {
    int dp[1001][1001];
    int solve(vector<int>&nums, int n , int index , int target){
        if(target < 0) return -2000;
        if(index == n){
            if(target == 0 ) return 0;
            else return -2000;
        }

        if(dp[index][target] != -1) return dp[index][target];
        
        int notpick = solve(nums, n , index+1 , target);
        
        
        int pick = 1 + solve(nums , n , index+1 , target - nums[index]);
        
        
        return dp[index][target] = max(pick , notpick);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        int ans = solve(nums, n , 0 , target);
        
        if(ans <= 0 ) return -1;
        return ans;
    }
};