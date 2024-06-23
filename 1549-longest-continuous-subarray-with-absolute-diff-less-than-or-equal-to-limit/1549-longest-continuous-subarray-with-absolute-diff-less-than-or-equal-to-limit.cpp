class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        

        int n = nums.size();
        multiset<int>st;

        int left =0, right = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int maxlen = INT_MIN;
        while(right < n){

            st.insert(nums[right]);
            maxi = *st.rbegin();
            mini = *st.begin();

            while(abs(maxi - mini) > limit){
                
                st.erase(st.find(nums[left]));
                left++;
                maxi = *st.rbegin();
                mini = *st.begin();
            }

            int len = right - left + 1;
            maxlen = max(maxlen , len);

            right++;
        }

        return maxlen;
    }
};