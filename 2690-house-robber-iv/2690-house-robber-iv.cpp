class Solution {
    bool solve(int capability , vector<int>&nums, int n , int k){
        int i = 0;

        while(i < n){
            if(nums[i] <= capability){
                k--;
                i+=2;
            }
            else{
                i++;
            }

            if(k == 0 ) return true;
        }

        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin() , nums.end());
        int high = *max_element(nums.begin() , nums.end());
        int n = nums.size();
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) /2;

            if(solve(mid , nums , n , k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};