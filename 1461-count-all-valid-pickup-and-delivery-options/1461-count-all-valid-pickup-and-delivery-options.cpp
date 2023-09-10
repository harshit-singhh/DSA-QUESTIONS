class Solution {
public:
    int countOrders(int n) {
        
        int mod = 1e9+7;

        if(n == 1) return 1;

        int result = 1;

        for(int i = 2 ; i <= n ; i++){
            long long steps = (i-1)*2 + 1;

            long long temp = steps * (steps+1) /2;

            result = ((result%mod)*(temp%mod))%mod;
        }

        return result;
    }
};