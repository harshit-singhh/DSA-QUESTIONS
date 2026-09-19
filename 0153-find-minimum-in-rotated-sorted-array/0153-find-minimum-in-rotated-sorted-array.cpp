class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n-1;

        int smallest = INT_MAX;
        while(left <= right){
            int mid = left + ( right - left) / 2;
            
            if(nums[left] > nums[mid]){
                smallest = min(smallest , nums[mid]);
                right = mid-1;
            }
            else{
                smallest = min(smallest , nums[left]);
                left = mid+1;
            }
        }
        return smallest;
    }
};