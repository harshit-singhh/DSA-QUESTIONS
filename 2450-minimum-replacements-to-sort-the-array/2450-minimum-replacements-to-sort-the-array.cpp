class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long operations = 0;

        int n = nums.size();

        for(int i = n-2 ; i>= 0 ; i--){
            if(nums[i]  < nums[i+1]) continue;

            else{
                long long parts = nums[i] / nums[i+1];
                if(nums[i] % nums[i+1] != 0) parts++;

                operations+= parts-1;

                nums[i] = nums[i] / parts;
            }
        }
        return operations;        
    }
};