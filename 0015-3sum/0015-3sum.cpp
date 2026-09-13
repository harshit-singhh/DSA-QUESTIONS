class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Step 1: Sort to use two pointers
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Optimization: If the smallest number is > 0, sum can never be 0
            if (nums[i] > 0) break;

            // Step 2: Skip duplicate elements for the 'i' pointer
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Move pointers after finding a triplet
                    j++;
                    k--;

                    // Step 3: Skip duplicates for 'j' and 'k'
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                } 
                else if (sum < 0) {
                    // Sum is too small, move the left pointer to increase sum
                    j++;
                } 
                else {
                    // Sum is too large, move the right pointer to decrease sum
                    k--;
                }
            }
        }
        return ans;
    }
};