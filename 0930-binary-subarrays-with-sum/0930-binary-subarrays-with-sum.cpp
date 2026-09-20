class Solution {
public:
    int findAtMost(vector<int>&nums , int n , int target){
        if(target < 0 ) return 0;

        int left = 0;
        int right = 0;

        int total = 0;
        int sum =0;
        while(right < n ){
            sum+= nums[right];
            while(sum > target){
                sum -= nums[left];
                left++;
            }

            total += right - left + 1;
            right++;
        }
        return total;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();

        return findAtMost(nums , n , goal) - findAtMost(nums , n , goal-1);

    }
};