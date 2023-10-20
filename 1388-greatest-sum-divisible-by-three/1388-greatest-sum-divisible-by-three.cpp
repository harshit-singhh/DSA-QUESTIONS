class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& nums,int i,int mod){
        if(i >= nums.size()){
            if(mod == 0)
                return 0;
            return INT_MIN;
        }
        if(dp[i][mod] != -1)
            return dp[i][mod];
        int take = nums[i] + solve(nums,i+1,(mod + nums[i])%3);
        int notTake = solve(nums,i+1,mod);
        return dp[i][mod] = max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size(),vector<int>(3,-1));
        return solve(nums,0,0);
    }
};