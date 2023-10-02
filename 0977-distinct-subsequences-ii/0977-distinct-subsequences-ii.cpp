class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long>dp(s.size()+1);
	    unordered_map<char , int>m;
	    
	    int mod = 1e9+7;
	    
	    dp[0] = 1; // empty string ke liye kar diya, because wo bhi ek distinct substring he
	    
	    for(int i = 1 ; i< dp.size() ; i++){
	        
	        char ch = s[i-1];
	        dp[i] = (dp[i-1]*2)%mod;
	        
	        if(m[ch] == 0){
	            m[ch] = i;
	        }
	        else{
	            int index = m[ch];
	            m[ch] = i;
	            dp[i] = (dp[i]%mod - dp[index-1]%mod)%mod;
	        }
	    }
	    
	    if(dp[s.size()] <0){
	        dp[s.size()]+=mod;
	    }
	    return (dp[s.size()]-1+mod)%mod;
    }
};