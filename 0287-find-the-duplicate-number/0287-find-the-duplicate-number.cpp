class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index = 0;

        int n = nums.size();

        while(index < n){

            int wantToSit = nums[index]; 
            if(nums[index] != index){

                if(nums[wantToSit] != wantToSit){

                    swap(nums[index] , nums[wantToSit]);
                    index--;
                }
            }
            index++;
        }

        int ans;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i){
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};