
#define mod 1000000007
class Solution {
    
    int dp[52][52][102];
    int solve(int n , int m , int k, int prev ){
        if(k < 0 ) return 0;
        if(n == 0){
            if(k==0) return 1;
            else return 0;
        }

        if(dp[n][k][prev] != -1) return dp[n][k][prev];

        long long take = 0;
        long long nottake = 0;
        for(int i = 1 ; i <= m ; i++){

            if(i > prev) take+= solve(n-1 , m , k-1 , i )%mod;
            else nottake+= solve(n-1 , m , k , prev )%mod;

        }

        return dp[n][k][prev] = (take + nottake)%mod;
            
        

    }
public:
    int numOfArrays(int n, int m, int k) {
        if(m < k || n < k) return 0;

        int count = 0;
        memset(dp , -1 , sizeof(dp));
        // unordered_map<int , unordered_map<int, unordered_map<int,int>>>dp;
        return solve(n , m , k ,0 );


    }
};