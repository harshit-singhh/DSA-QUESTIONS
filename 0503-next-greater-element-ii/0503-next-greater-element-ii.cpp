class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;

        int n = nums.size();
        vector<int>ans;
        for(int i = 2*n-1 ; i >= 0 ; i--){
            while(!st.empty() && nums[i%n] >= st.top()){
                st.pop();
            }
            if(!st.empty()){
                if(i <= n-1) ans.push_back(st.top());
                st.push(nums[i%n]);
            }
            else if(st.empty()){
                if(i <= n-1) ans.push_back(-1);
                st.push(nums[i%n]);
            }

        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};