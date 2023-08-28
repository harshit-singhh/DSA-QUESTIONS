class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>ans(n);

        int sum = 0;

        for(int i = 0 ; i < n ; i++ ){
            sum+=nums[i];

            left[i] = sum - nums[i];
        }

        sum = 0;

        for(int i = n - 1; i >= 0 ; i--){
            sum += nums[i];

            right[i] = sum - nums[i];
        }

        for(int i = 0 ; i < n ; i++){
            ans[i] = abs(left[i] - right[i]);
        }
        return ans;
    }
};