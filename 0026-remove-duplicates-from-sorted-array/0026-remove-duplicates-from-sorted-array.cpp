class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        for(int i = 0 ; i < n ; i ++){
            if(nums[i] != nums[index]){
                index++;
                nums[index] = nums[i];
            }

        }

        return index+1;
    }
};