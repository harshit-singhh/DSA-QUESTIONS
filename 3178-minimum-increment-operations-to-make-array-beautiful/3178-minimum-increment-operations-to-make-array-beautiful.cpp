class Solution {
public:
    int n; 
    vector<long long> dp;
    long long solve(int ind,vector<int>& nums, int k)
    {
        if(ind>n-3)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        //option 1
        long long op1 = max(0,k-nums[ind]) + solve(ind+1,nums,k);
        //option 2
        long long op2 = max(0,k-nums[ind+1]) + solve(ind+2,nums,k);
        //option 3
        long long op3 = max(0,k-nums[ind+2]) + solve(ind+3,nums,k);
        
        return dp[ind] = min(op1,min(op2,op3));
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n,-1);
        return solve(0,nums,k);
    }
};

// class Solution {
// public:
//     long long minIncrementOperations(vector<int>& nums, int k) {
//         // set<pair<int,int>>st;
//         unordered_map<int,int>mp;
        
//         int n= nums.size();
        
//         int left = 0 , right = 2;
        
        
        
//         while(right < n){
//             int maxi = INT_MIN;
//             int maxindex = -1;
            
//             if(nums[right] >= nums[left+1] && nums[right] >= nums[left]) {
//                maxi = nums[right];
//                maxindex = right;
//            }
            
//             else if(nums[left+1] >= nums[left] && nums[left+1] >= nums[right]){
//                 maxi = nums[left+1];
//                 maxindex = left+1;
//             }
            
//             else{
//                 maxi = nums[left];
//                 maxindex = left;
//             }
           
            
           
                    
//             if(maxi < k){
//                 nums[maxindex] = k;
//                 mp[maxindex] = k - maxi;
//             }
                    
//             right++;
//             left++;
            
             
//         }
                    
//         long long total = 0;
        
//         for(auto it: mp){
//             total += it.second;
//         }
        
//         return total;
//     }
// };