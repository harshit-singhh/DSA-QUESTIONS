class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int thirdElement = INT_MIN;

        stack<int>st;

        int n = nums.size();

        for(int i = n -1; i >= 0 ; i--){
            if(nums[i] < thirdElement) return true;
            
            while(!st.empty() && nums[i] > st.top()){
                thirdElement = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};