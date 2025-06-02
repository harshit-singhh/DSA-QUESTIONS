class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int>st;

        for(auto it : nums){
            st.insert(it);
        }

        int maxSize = INT_MIN;
        for(auto it = st.begin() ; it != st.end() ; it++){
            int num = *it;

            if(st.find(num-1) == st.end()){
                int size = 0;

                while(st.find(num) != st.end()){
                    size++;
                    num++;
                }

                maxSize = max(maxSize , size);


            }
        }

        return maxSize;
    }
};