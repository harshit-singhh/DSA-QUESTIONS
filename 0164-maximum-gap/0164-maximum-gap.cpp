class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1 ) return 0;


        set<int>st;

        for(auto it: nums){
            st.insert(it);
        }

        int maxi = 0;

        // int prev = *(st.begin());
        // cout<<prev<<" ";
        
        // for(auto it: st){
        //     maxi = max(maxi , it - prev);
        //     prev = it;
        // }

        // return maxi;

        auto it = st.begin();
        auto nextIt = st.begin();
        ++nextIt;

        for (; nextIt != st.end(); ++it, ++nextIt) {
            maxi = std::max(maxi, *nextIt - *it);
        }

        return maxi;
    }
};