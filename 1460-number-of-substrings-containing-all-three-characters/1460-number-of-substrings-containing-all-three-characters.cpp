class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0 , right = 0, count = 0;
        vector<int>freq(26,0);
        
        while(right < s.size()){
            freq[s[right] - 'a']++;
            
            while(freq[0] >= 1 && freq[1] >= 1 && freq[2] >= 1){
                count+= (s .size() - right);
                freq[s[left] - 'a']--;
                left++;
            }
            
            right++;
        }
        
        return count;
    }
};