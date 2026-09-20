class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        
        int left = 0, right = 0;
        int max_len = 0;
        int max_freq = 0;

        while (right < n) {
            // 1. Add current character to map
            mp[s[right]]++;
            
            // 2. Track maximum frequency of any single character in current window
            max_freq = max(max_freq, mp[s[right]]);

            // 3. If replacements needed exceed k, shrink window from left
            while ((right - left + 1) - max_freq > k) {
                mp[s[left]]--;
                left++;
            }

            // 4. Update max valid window length
            max_len = max(max_len, right - left + 1);
            
            right++;
        }

        return max_len;
    }
};