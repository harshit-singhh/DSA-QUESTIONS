class Solution {
    private:
    int divide(int value , vector<int>&nums){

        int sum = 0;

        for(int i = 0 ; i < nums.size() ; i ++){
            double divide = (double)nums[i]/value;
            sum+= ceil(divide);
        }

        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            int sum = divide(mid,nums);

            if(sum > threshold){
                low = mid + 1;
            }
            else if(sum <= threshold){
                ans = mid;
                high = mid -1;
            }
        }

        return ans;


    }
};