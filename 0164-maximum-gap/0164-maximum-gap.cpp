class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1 ) return 0;


        set<int>st;

        for(auto it: nums){
            st.insert(it);
        }

        int maxi = INT_MIN;

        int prev = *(st.begin());
        cout<<prev<<" ";
        
        for(auto it: st){
            maxi = max(maxi , it - prev);
            prev = it;
        }

        return maxi;
    }
};