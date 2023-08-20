class Solution {
public:
    bool repeatedSubstringPattern(string s) {
         vector<int>lps(s.size());
	    
	    int left = 0;
	    int right = 1;
	    
	    lps[left] = 0;
	    int n = s.size();
	    while(right < n){
	        if(s[left] == s[right]){
	            lps[right] = left+1;
	            right++;
	            left++;
	        }
	        else{
	            if(left > 0) left = lps[left-1];
	            else if(left == 0){
	                
	                lps[right] = 0;
	                right++;
	            }
	            
	        }
	    }
	    
	    if(lps[n-1]==0)
            return 0;
        int count = n - lps[n-1];
        if(n%count==0)
            return 1;
        return 0;
    }
};