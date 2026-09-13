class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxSize = 0;
        int len =0;
        for(int i = 0 ; i < n ; i ++){
            if(nums[i] == 1){
                len++;
                maxSize = max(maxSize , len);
            }
            else{
                len= 0;
            }
        }
        return maxSize;
    }
};