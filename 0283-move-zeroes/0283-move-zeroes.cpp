class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int firstZeroIndex;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0 ){
                firstZeroIndex = i;
                break;
            }
        }

        for(int i = firstZeroIndex +1 ; i < n ; i++){
            if(nums[i] != 0 ){
                swap(nums[i] , nums[firstZeroIndex]);
                firstZeroIndex++;
            }
        }
    }
};