bool comp(string &str1 , string&str2){
    return str1.size() < str2.size();
}

class Solution {
    private:

    bool isPossible(string s1 , string s2){
        if(s1.size() != s2.size() +1) return false;
        
        int first = 0;
        int second = 0;
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }

        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp);

        int maxi = 1;

        int n = words.size();

        vector<int>dp(n , 1);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(isPossible(words[i] , words[j])){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }


        return maxi;

    }
};