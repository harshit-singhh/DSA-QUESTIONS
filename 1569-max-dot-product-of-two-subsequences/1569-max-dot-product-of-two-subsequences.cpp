class Solution {
    int dp[501][501];
    int solve(vector<int>& arr1 ,int n , int index1 , vector<int>&arr2 , int m ,  int index2){
        if(index1 == n || index2 == m ) return INT_MIN;

        if(dp[index1][index2] != -1) return dp[index1][index2];

        int maxi = INT_MIN;
        
        
        int part1 = arr1[index1]*arr2[index2] + max(0,solve(arr1 , n , index1+1 , arr2 , m , index2+1));
        int part2 = solve(arr1 , n , index1+1 , arr2 , m , index2);
        int part3 = solve(arr1 , n , index1 , arr2 , m , index2+1);

        maxi = max(part1 , max(part2 , part3));

        return dp[index1][index2] = maxi;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp , -1 , sizeof(dp));
        return solve(nums1 , n , 0, nums2 , m , 0 );
    }
};