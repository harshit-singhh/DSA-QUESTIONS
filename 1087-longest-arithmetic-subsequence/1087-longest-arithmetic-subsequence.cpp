class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
         int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 0));

        int ans = -1;

        for(int right = 0; right<n; right++)
        {
            for(int left = 0; left<right; left++)
            {
                int diff = nums[right] - nums[left]+500;
                
                dp[right][diff] = (dp[left][diff] > 0) ? dp[left][diff] + 1 : 2;

                ans = max(ans, dp[right][diff]);
            }
        }

        return ans; 
    }
};