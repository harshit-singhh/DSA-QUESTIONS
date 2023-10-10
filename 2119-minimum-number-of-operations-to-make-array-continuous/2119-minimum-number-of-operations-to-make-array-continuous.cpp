
class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Sort the vector in ascending order
        sort(nums.begin(), nums.end());

        // Initialize variables
        int n = nums.size(); // Number of elements in the vector
        int left = 0; // Left pointer for the sliding window
        int maxCount = 1; // Initialize the maximum count of distinct elements
        int currentCount = 1; // Initialize the count of distinct elements in the current window

        // Iterate through the vector to find the minimum operations
        for (int right = 1; right < n; ++right) {
            // Check if the current element is equal to the previous one
            if (nums[right] == nums[right - 1]) {
                continue; // Skip duplicates
            }

            // Check if the current window size is less than or equal to the difference between the maximum and minimum values
            while (nums[right] - nums[left] > n - 1) {
                // Move the left pointer to shrink the window
                if(left<n && nums[left+1]==nums[left]){
currentCount++;
}
                left++;
                currentCount--;
            }

            // Update the count of distinct elements in the current window
            currentCount++;

            // Update the maximum count
            maxCount = max(maxCount, currentCount);
        }

        // Calculate the minimum operations
        int minOps = n - maxCount;

        return minOps;
    }
};



// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int maxi = *max_element(nums.begin() , nums.end());
//         int mini = *min_element(nums.begin() , nums.end());

//         int n = nums.size();
//         unordered_set<int>st;
//         unordered_map<int,int>mp;

//         for(auto it: nums){
//             mp[it]++;
//             st.insert(it);
//         }

//         int duplicate = 0;
//         for(auto it: mp){
//             if(it.second > 1){
//                 duplicate += it.second-1;
//             }
//         }

//         if(maxi - mini == n-1) return 0 + duplicate;

//         int to_form = n-1;

//         int curr = maxi - mini;

//         int extra = curr - to_form;

//         int curr_maxi = maxi - extra;
//         int curr_mini = mini + extra;

//         int count1 = 1 , count2 = 1;

//         for(auto it: st){
//             if(it> curr_maxi && it != maxi){
//                 count1++;
//             }

//             if(it< curr_mini && it != mini){
//                 count2++;
//             }
//         }

//         return min(count1+duplicate , count2+duplicate);
//     }
// };