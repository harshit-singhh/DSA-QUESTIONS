class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        // to check for increasing

        bool inc = true;
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < nums[i-1]){
                inc = false;
                break;
            }
        }

        bool dec = true;

        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                dec = false;
                break;
            }
        }

        return inc || dec;
    }
};