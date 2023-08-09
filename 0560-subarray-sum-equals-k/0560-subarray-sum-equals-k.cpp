class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        m[0] = 1;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int rem = sum - k;
            if(m.find(rem) != m.end()){
                count+=m[rem];
            }
            m[sum]++;
        }

        return count;
    }
};