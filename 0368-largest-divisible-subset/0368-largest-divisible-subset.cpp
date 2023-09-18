class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int>dp(n , 1);
        vector<int>hash(n);
        for(int i = 0 ; i < n ; i++) hash[i] = i;
        int lastindex = 0;
        int maxi = -1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< i ; j++){
                if(nums[i]%nums[j] == 0){

                   if(dp[j] + 1 > dp[i]){
                       dp[i] = dp[j] + 1;
                       hash[i] = j;
                   }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }

        vector<int>ans;

        while(hash[lastindex] != lastindex){

            ans.push_back(nums[lastindex]);
            lastindex = hash[lastindex];
        }

        ans.push_back(nums[lastindex]);

        reverse(ans.begin() , ans.end());

        return ans;


    }
};