class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;

        for(auto it: nums) st.insert(it);

        int len = 0;
        int maxlen = 0;
        int element;
        bool first = true;
        for(auto it: st){
            if(first == true){
                first = false;
                element = it;
                len++;
                maxlen = max(maxlen , len);
            }
            else{
                if(it == element + 1){
                    len++;
                    element = it;
                    maxlen = max(maxlen , len);
                }
                else if(it == element){
                    continue;
                }
                else if(it != element + 1){
                    element = it;
                    len = 1;
                }
            }
        }

        return maxlen;

    }
};