class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();

        int left = 0 , right = 0 , len = 0 , minlen = INT_MAX;
        int sum = 0;
        while(right < n ){
            sum += nums[right];

            while(sum >= target){
                len = right - left + 1;
                minlen = min(minlen , len);

                sum -= nums[left];
                left++;
            }

            right++;
        }

        return minlen == INT_MAX ? 0 : minlen;
        // return minlen;
    }
};