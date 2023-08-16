class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int dip = -1;

        int n = nums.size();

        for(int i = n-2 ; i >= 0 ; i --){
            if(nums[i] < nums[i+1]){
                dip = i;
                break;
            }
        }
        if(dip == -1){
            reverse(nums.begin() , nums.end());
        }

        else{

            for(int i = n-1 ; i >= 0 ; i--){
                if(nums[i] > nums[dip]){
                    swap(nums[i] , nums[dip]);
                    break;
                }
            }

            reverse(nums.begin()+dip+1 , nums.end());
        }


    }
};