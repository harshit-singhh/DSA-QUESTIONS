class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>st;
        int n = nums.size();
        for(auto it : nums){
            st.insert(it);
        }

        int maxLen = 0;
        for(auto it = st.begin() ; it !=  st.end() ; it++){

            if(st.find((*it) + 1) == st.end()){
                // this is the last element of the consecutive sequence
                int len = 1;
                auto temp = (*it) - 1;
                while(st.find(temp) != st.end()){
                    len++;
                    temp--;
                }
                
                maxLen = max(maxLen , len);
            }
        }
        return maxLen;
    }
};