class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int onecount = 0;
        vector<int>arr(2*n);
        for(int i = 0 ;  i < n ; i++){
            arr[i] = nums[i];
            arr[i+n] = nums[i];

            if(nums[i] == 1){
                onecount++;
            }
        }

        int zerocount = 0;
        int left = 0;
        int right = 0;
        for(right = 0 ; right < onecount ; right++){
            if(arr[right] == 0) zerocount++;
        }

        int minzero = INT_MAX;
        minzero = min(minzero , zerocount);
        while(right < 2*n){

            if(arr[right] == 0){
                zerocount++;
            }

            if(arr[left] == 0){
                zerocount--;
            }
            left++;
            minzero = min(minzero , zerocount);
            right++;

        }

        return minzero;


    }
};