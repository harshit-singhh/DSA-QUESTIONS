class Solution {
public:
    
    int solve(vector<int>nums , int n , int goal){
        int left = 0, right = 0;
        if(goal <0  ) return 0;
        int count = 0;
        int sum = 0;
        while(right < n){
            sum+=nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }

            count+= right-left+1;
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        return solve(nums,n, goal) - solve(nums,n,goal-1);
    }
};