class Solution {
    private:
    int solve(vector<int>&nums , int target , int index , int sum){
        if(sum > target) return 0;
        // if(sum == target) return 1;
        if(index == nums.size()){
            if(sum == target) return 1;
            return 0;
        }
        int pick = solve(nums , target , index + 1, sum + nums[index]);
        int notpick = solve(nums , target , index +1 , sum);

        return pick + notpick;
    }

    public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        if((totalsum - target ) %2 != 0) return false;

        int sum = ( totalsum - target) /2;

        return solve(nums , sum ,0 , 0);
    }
};