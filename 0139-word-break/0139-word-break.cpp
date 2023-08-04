class Solution {
    private:

    bool solve(string &s , unordered_set<string>&st , int index , vector<int>&dp){

        if(index == s.size()) return true;

        if(dp[index] != -1) return dp[index];
        string temp = "";
        for(int i = index ; i< s.size() ; i++){
            temp+=s[i];
            if(st.find(temp) != st.end()){
                if(solve(s , st , i+1 ,dp) == true) return dp[index] = true;;
            }
        }
        return dp[index] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;

        for(auto it : wordDict){
            st.insert(it);
        }
        vector<int>dp(300 , -1);
        return solve(s , st , 0 ,dp);
    }
};