#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin() , arr.end());

        int n = arr.size();

        unordered_map<int, int>mp;

        for(int i = 0 ; i < n ; i++){
            mp[arr[i]] = i;
        }

        vector<long long>dp(n , 1);


        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < i ; j++){
                
                int root = arr[i];
                int oneChild = arr[j];

                int otherChild = root / oneChild;
                if(root % oneChild == 0 && mp.find(otherChild) != mp.end()){
                    int otherChildIndex = mp[otherChild];
                    dp[i] += dp[j]*dp[otherChildIndex];
                    dp[i]%=mod;
                }

            }
        }

        long long total = 0;

        for(int i = 0 ; i < n ; i++){
            total += dp[i];
            total%=mod;
        }

        return total;


    }
};