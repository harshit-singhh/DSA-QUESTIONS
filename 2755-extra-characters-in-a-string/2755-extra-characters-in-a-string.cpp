class Solution {
    int solve(int index , string s , unordered_set<string>&st, vector<int>&dp){
        if(index == s.size()) return 0;

        if(dp[index] != -1) return dp[index];
        string temp = "";
        int minextra = s.size();
        for(int i = index  ; i < s.size() ; i ++){
            int extra = 0;
            temp.push_back(s[i]);
            if(st.find(temp) == st.end()){
                extra += temp.size();
            }
            int totalextra = extra + solve(i+1 , s , st  ,dp);

            minextra = min(minextra , totalextra);
        }

        return dp[index] = minextra;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st;

        for(auto it : dictionary){
            st.insert(it);
        }

        vector<int>dp(s.size() + 1 , -1);
        int index = 0;

        return solve(index , s , st ,dp);
    }
};