class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;

        for(int i = 0  ; i< t.size() ; i++){
            if(t[i] == s[index]){
                index++;
            }
            if(index == s.size()) break;
        }

        if(index == s.size()) return true;
        return false;
    }
};