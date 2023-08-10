class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0; 
        int n = nums.size(); 
        int high = n-1;

        while(low <= high && nums[low] == nums[high]){
            if(nums[low] == target || nums[high] == target) return true;
            low ++;
            high --;
        }
        

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return true;
            
            if(nums[mid] >= nums[low]){ // left part is sorted
                if(target < nums[mid] && target >= nums[low]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid] <= nums[high]){
                if(target > nums[mid] && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};