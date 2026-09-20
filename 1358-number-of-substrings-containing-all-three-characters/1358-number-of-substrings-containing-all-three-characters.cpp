class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;

        int allcount = 0;

        unordered_map<char , int>mp;
        int total = 0;
        while(right < n){
            if(mp.find(s[right]) == mp.end()){
                allcount++;
            }
            mp[s[right]]++;

            while(allcount >= 3){
                total += n - right;
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    allcount--;
                    mp.erase(s[left]);
                }
                left++;
            }

            right++;

        }
        return total;
    }
};