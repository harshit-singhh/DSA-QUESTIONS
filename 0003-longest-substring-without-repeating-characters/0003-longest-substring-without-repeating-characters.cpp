class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;

        int maxLen = 0;
        unordered_set<char>st;

        while(right < n){

            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left ++;
            }

            int len = right - left + 1;
            maxLen = max(maxLen , len);
            st.insert(s[right]);
            right++;

        }
        return maxLen;
    }
};