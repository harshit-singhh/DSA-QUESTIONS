class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        int left = 0 , right = 0 , maxi = 0;
        
        set<int>st; 
        
        while(right < S.size()){
            
            int length = 0;
            
            if(st.find(S[right]) == st.end()){
                st.insert(S[right]);
                length = right - left +1;
            }
            
            else{
                
                while(st.find(S[right]) != st.end()){
                    st.erase(S[left]);
                    left++;
                }
                length = right - left +1;
                st.insert(S[right]);
            }
            
            maxi = max(maxi,length);
            right++;

        }
        
        if(maxi == 0 )return 0;
        return maxi;
        
    }
};