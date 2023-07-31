class Solution {
    private:
     bool solve( vector<int>&arr, int N , int index , int sum , int target , vector<vector<int>>&dp){
        if(index >= N ) return false;
        if(sum == target) return true;
        if(sum > target) return false;
        
        if(dp[index][sum] != -1 )return dp[index][sum];
        
        bool pick = solve(arr , N , index +1 , sum+ arr[index] , target , dp);
        
        bool notPick = solve( arr, N , index +1 , sum , target , dp);
        
        return dp[index][sum] = (pick || notPick);
        
    }
public:
    bool canPartition(vector<int>& arr) {
        int N = arr.size();
         int sum = accumulate(arr.begin(), arr.end(), 0);
        // agar sum odd he then its impossible to divide into 2 parts
        if(sum%2 != 0) return 0;
        
        //agar sum even he then we can search for sum/2 in the array, if sum/2 is present then this means ki baki bhi pre
        // sent hoga hi
        
        vector<vector<int>>dp(N , vector<int>(sum/2 , -1));
        return solve(arr , N , 0 , 0 , sum/2 , dp);
    }
};