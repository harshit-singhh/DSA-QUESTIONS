



class Solution {
    private:
    int solve(vector<int>&nums , int i , int j , vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = -1e9;

        for(int k = i ; k <= j ; k++){
            int cost = nums[i-1]*nums[k]* nums[j+1] + solve(nums , i , k-1 ,dp) + solve(nums, k+1 , j ,dp);
            maxi = max(cost , maxi);
        }
        return dp[i][j] = maxi;
    }

    // tabulation

    int solvetab(vector<int>&nums , int n){
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        for(int i = n-2 ; i >= 1 ; i--){
            for(int j = 1 ; j <= n-2 ; j++){
                if(i > j) continue;
                int maxi = -1e9;
                for(int k = i ; k <= j ; k++){
                    int cost = nums[i-1]*nums[k]* nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(cost , maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int n = nums.size();

        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));

        // return solve(nums , 1 , n-2 ,dp );
        return solvetab(nums , n);
    }
};


// THIS WAS MY SOLUTION , AND IT WORKED ACTUALLY , BUT MEMOIZE NHI HO RHA 12 TEST CASES PASSED.

// class Solution {
//     private:
//     int solve(vector<int>&nums, int i , int j){
//         if(i == j) return nums[i];

     

//         int maxi = -1e9;
//         for(int k = i ; k <= j ; k++){
//             int temp = nums[k];

//             int to_multiply = nums[k-1] * nums[k] * nums[k+1] ;
//             nums.erase(nums.begin() + k);
//             // int len = nums.size();
//             int total = to_multiply + solve(nums , 1 , j -1 );
//             nums.insert(nums.begin() + k , temp );
//             maxi = max(total , maxi);
//         }

//         return maxi;
//     }
// public:
//     int maxCoins(vector<int>& nums) {
//         nums.push_back(1);
//         nums.insert(nums.begin(), 1);

//         int n = nums.size();

        

//         return solve(nums , 1 , n-2 );
//     }
// };