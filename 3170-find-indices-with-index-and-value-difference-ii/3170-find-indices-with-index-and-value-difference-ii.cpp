class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        int maxi = INT_MIN;
        int mini  = INT_MAX;
        int maxIndex = -1 , minIndex = -1;
        int n = nums.size();
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            if(i >= indexDifference){
                if(nums[index] > maxi){
                    maxi = nums[index];
                    maxIndex = index;
                }
                if(nums[index] < mini){
                    mini = nums[index];
                    minIndex = index;
                }


                if(abs(nums[i] - maxi) >= valueDifference){
                    return {i , maxIndex};
                }
                if( abs(nums[i] - mini) >= valueDifference){
                    return {i , minIndex};
                }
                index++;
            }
        }

        return {-1 , -1};
    }
};