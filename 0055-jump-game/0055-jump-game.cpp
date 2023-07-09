class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = nums[0];

        int n = nums.size();

        if(n == 1) return true;

        if(nums[0] == 0 && n != 0) return false;
        

        int i = 0;
        int steps = nums[0];

        while(steps){
            i++;
            maxreach = max(maxreach , i+nums[i]);
            steps --;

            if(steps == 0){
                if((maxreach < n-1) && (i >= maxreach)) return false;

                else{
                    steps = maxreach - i;
                }
            }

            if(i + steps >= n-1) return true;
        }

        return false;
    }
};