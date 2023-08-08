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


    // int characterReplacement(string S, int K) {
    //     int n = S.size();
    //     vector<int> mp(26, 0);
    //     int head = 0; // right
    //     int tail = 0; // left
    //     int res = 0;
        
    //     for(int head = 0; head < n; head++) {
    //         mp[S[head] - 'A']++;
            
    //         while((head - tail + 1) - *max_element(mp.begin(), mp.end()) > K) {
    //             mp[S[tail] - 'A']--;
    //             tail++;
    //         }
            
    //         res = max(res, (head - tail + 1));
    //     }
        
    //     return res;
    
    
    // }
};