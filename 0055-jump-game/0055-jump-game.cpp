class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();

        // if(n == 1) return true;
        int i = 0;

        int maxWeCanGo = nums[0];
        while(i < n){
            int weCanGo = i+nums[i];
            maxWeCanGo = max(maxWeCanGo , weCanGo);

            if(maxWeCanGo >= n-1) return true;

            else if(i == maxWeCanGo){
                return false;
            }

            else if(maxWeCanGo > i){
                i++;
            }

        }

        return true;
    }
};