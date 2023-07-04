class Solution {
public:

    int maxFrequentValue(unordered_map<char,int>&m){
        
        int maxi = 0;
        
        for(auto i : m){
            maxi = max(maxi , i.second);
        }
        
        return maxi;
    }

    
    int characterReplacement(string S, int K) {
        int left = 0 , right = 0 ;
        int maxlength = 0;
        
        unordered_map<char,int>m;
        
        while(right < S.size()){
            
            
            m[S[right]]++;

            while(((right - left +1) - maxFrequentValue(m)) > K){
                m[S[left]]--;
                
                left++;
            }
                

            int windowLength = right-left+1;
            maxlength = max(maxlength,windowLength);
            right++;

        }
        
        return maxlength;
    }
};