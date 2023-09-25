class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int>mp;

        int n = t.size();

        for(int i = 0 ; i < n ; i++){
            mp[t[i]]++;
        }

        for(int i = 0 ; i < n-1 ; i++){
            mp[s[i]]--;
        }

        char ans;
        for(auto it: mp){
            if(it.second == 1){
                ans = it.first;
                break;
            }
        }

        return ans;
    }
};