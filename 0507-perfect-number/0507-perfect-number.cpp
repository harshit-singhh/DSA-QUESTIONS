class Solution {
public:
    bool checkPerfectNumber(int N) {
        if(N == 1 || N ==0) return 0;
        long long count = 1;
        
        for(long long i = 2 ; i <= sqrt(N) ; i++){
            
            if(N%i == 0){
                count += i + (N/i);
            }
            
        }
        
        return count == N;
    }
};