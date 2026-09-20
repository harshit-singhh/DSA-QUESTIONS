class Solution {
public:
    int atMost(vector<int>&nums , int n , int k){
        int uniqueElem = 0;
        unordered_map<int ,int>mp;
        int left = 0;
        int right = 0;

        int total = 0;

        while(right < n){

            if(mp.find(nums[right]) == mp.end()){
                uniqueElem++;
            }
            mp[nums[right]]++;

            while(uniqueElem > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    uniqueElem--;
                    mp.erase(nums[left]);
                }
                left++;
            }

            int subarrays = right - left + 1;
            total += subarrays;
            right++;
        }

        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();

        return atMost(nums, n , k) - atMost(nums , n , k-1);
    }
};