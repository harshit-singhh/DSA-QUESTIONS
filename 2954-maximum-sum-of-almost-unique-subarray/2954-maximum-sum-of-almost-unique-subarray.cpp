class Solution {
    private:
    long long findsum(unordered_map<long long,long long>&mp){
        long long sum = 0;
        
        for(auto it: mp){
            sum += it.first*it.second;
        }
        return sum;
    }
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        unordered_map<long long ,long long>mp;
        
        int left = 0;
        int right = 0;
        long long maxsum = 0;
        
        int n = nums.size();
        
        while(right < n){
            mp[nums[right]]++;
            
            
            if(right - left + 1 == k){
                if(mp.size() >= m){
                    long long sum = findsum(mp);
                    maxsum = max(maxsum , sum);
                }
                mp[nums[left]]--;
                if(mp[nums[left]] == 0 )mp.erase(nums[left]);
            }
            
            if(right-left + 1 == k)left++;
            right++;
        }
        
        return maxsum;
    }
};