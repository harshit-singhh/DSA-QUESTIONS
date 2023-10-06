class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        int mindiff = INT_MAX;
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0 ; i < n-2 ; i++){

            int j = i+1;
            int k = n-1;

            while(j < k){

                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return target;
                if(abs(sum - target) < mindiff){
                    mindiff = abs(sum - target);
                    ans = sum;
                }

                if(sum > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        return ans;
    }
};