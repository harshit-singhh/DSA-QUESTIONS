class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m1, m2;
        if(s.size() != t.size()) return false;

        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            m1[s[i]]++;
        }

        for(int i = 0 ; i < n ; i++){
            m2[t[i]]++;
        }

        for(auto it: m2){
            if(it.second != m1[it.first]) return false;
        }

        return true;
    }
};