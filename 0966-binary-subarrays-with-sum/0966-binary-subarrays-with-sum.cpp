class Solution {
     int Atmost(vector<int>& arr, int n, int target){
        
        int sum = 0;
        if(target < 0) return 0;
        
        int totalSubarrays = 0;
        
        int left = 0 , right = 0;
        
        while(right < n){
            
            sum+=arr[right];
            
            while(sum > target){
                sum -= arr[left];
                left++;
            }
            
            totalSubarrays += right - left +1; // we can use this formula also to calculate the 
            // total number of subarrays between right and left
            right++;
        }
        
        return totalSubarrays;
    }
public:
    int numSubarraysWithSum(vector<int>& arr, int target) {
        int n = arr.size();
         return Atmost(arr,n,target) - Atmost(arr,n,target-1);
    }
};