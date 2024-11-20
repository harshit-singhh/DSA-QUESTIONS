class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        int maxi = 0;
        int aCount  = 0  , bCount = 0 , cCount = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a' ) aCount++;
            else if(s[i] == 'b')bCount++;
            else cCount++;
        }
        if(aCount < k || bCount < k || cCount < k) return -1;

        int left  = 0 , right = 0;
        while(right < n){
            if(s[right] == 'a') aCount--;
            else if(s[right] == 'b') bCount--;
            else cCount--;

            while(aCount < k || bCount <k || cCount < k){
                if(s[left] == 'a') aCount++;
                else if(s[left] == 'b') bCount++;
                else cCount++;

                left++;
            }

            maxi = max(maxi  , right - left + 1);
            right++;
        }
        return n - maxi;
    }
};