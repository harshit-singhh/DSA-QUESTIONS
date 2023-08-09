class Solution {
    bool ispossible(vector<int>&nums , int diff , int p){
        int count = 0;
        int n = nums.size();

        int left = 0;

        while(left < n-1){
            if((nums[left+1] - nums[left]) <= diff){
                count++;
                if(count >= p) return true;
                left = left+2;
            }
            else{
                left++;
            }
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(), nums.end());
        if(p == 0) return 0;
        int low = 0;
        int high = 1e9+7;

        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) /2;

            if(ispossible(nums , mid , p)){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};