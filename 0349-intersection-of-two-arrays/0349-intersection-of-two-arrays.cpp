class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int>result;
        unordered_set<int>st;
        for(auto &num : nums1){
            st.insert(num);
        }
        for(auto & num : nums2){
            if(st.find(num) != st.end()){
                result.push_back(num);
                st.erase(num);
            }
        }
        return result;
    }
};