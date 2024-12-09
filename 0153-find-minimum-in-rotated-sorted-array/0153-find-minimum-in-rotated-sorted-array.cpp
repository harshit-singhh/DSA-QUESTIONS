class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int lowest = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            //finding sorted part
            if(nums[low] <= nums[mid]){
                lowest = min(lowest , nums[low]);
                low = mid+1;
            }
            else if(nums[mid] <= nums[high]){
                lowest = min(lowest , nums[mid]);
                high = mid -1;
            }
        }
        return lowest;
    }
};