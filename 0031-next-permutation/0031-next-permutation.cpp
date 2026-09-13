class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();


        int right = n-2;
        int index_to_swap = -1;
        while(right >= 0){
            if(nums[right] < nums[right+1]){
                index_to_swap = right;
                break;
            }
            right--;
        }

        if(right < 0 ) return reverse(nums.begin() , nums.end());
        int first_greater_element = -1;
        right = n-1;
        while(right > index_to_swap){
            if(nums[right] > nums[index_to_swap]){
                swap(nums[right] , nums[index_to_swap]);
                break;
            }
            right --;
        } 

        reverse(nums.begin() + index_to_swap + 1 , nums.end());
    }
};