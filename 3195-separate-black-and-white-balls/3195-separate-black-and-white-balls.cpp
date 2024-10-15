class Solution {
public:
    long long minimumSteps(string s) {
        
        long long onecount = 0;
        long long total = 0;
        int n = s.size();
        
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '1'){
                total += n-i - 1;
                total -= onecount;
                onecount++;
            }
        }
        
        return total;
    }
};