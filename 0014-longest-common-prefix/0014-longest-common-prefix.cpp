class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if(strs.size() == 1){
            return strs[0];
        }
        
        
        for(int i = 0 ; i < strs[0].size() ; i++){
            char ch = strs[0][i];
            bool issame = true;

            for(int j = 1 ; j < n ; j++){
                if(strs[j][i] != ch){
                    issame = false;
                    break;
                }
                
            }
            if(issame) ans.push_back(ch);
            if(issame == false) break;
        }

        return ans;
    }
};