
#define mod 1000000007
class Solution {

    int dp[20002][26];
    long long solve(int n , int len , char prev){
        if(len == n ) return 1;

        if(dp[len][prev - 'a'] != -1) return dp[len][prev - 'a'];
        long long total = 0;

        if(prev == 'b'){
            total = solve(n , len+1 , 'a') + solve(n , len+1 , 'e') + solve(n , len+1 , 'i') +
             solve(n , len+1 , 'o') + solve(n , len+1 , 'u');
        }
        else if(prev == 'a'){
            total = solve(n , len+1 , 'e');
        }
        else if(prev == 'e'){
            total = solve(n , len+1 , 'a') + solve(n , len+1 , 'i');
        }
        else if(prev == 'i'){
            total = solve(n , len+1 , 'a') + solve(n , len+1 , 'e') +
             solve(n , len+1 , 'o') + solve(n , len+1 , 'u');
        }
        else if(prev == 'o'){
            total = solve(n , len+1 , 'i') + solve( n , len+1 , 'u');
        }

        else if(prev == 'u'){
            total = solve(n , len+1 , 'a');
        }

        return dp[len][prev - 'a']=total%mod;
    }
public:
    int countVowelPermutation(int n) {
        memset(dp  , -1 , sizeof(dp));
        return solve(n , 0 , 'b');
    }
};