class Solution {
    int findtotal(vector<int>& arr, int n){
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
        }
        return sum;
    }
    
    int findMax(vector<int>& arr, int n){
        int maxsum = INT_MIN;
        int sum =0;
        
        for(int i =0 ; i < n ; i++){
            sum += arr[i];
            maxsum = max(sum , maxsum);
            if(sum < 0){
                sum = 0;
            }
            
        }   
        return maxsum;
        
    }
    
    int findMin(vector<int>& arr, int n){
        int minsum = INT_MAX;
        int sum =0;
        
        for(int i =0 ; i< n ; i++){
            sum+=arr[i];
            minsum = min(sum , minsum);
            if(sum > 0){
                sum = 0;
            }
            
        }
        return minsum;
    }
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int num = arr.size();
        int totalsum = findtotal(arr , num);
        int maxSum = findMax(arr , num);
        int minSum = findMin(arr ,num);
        
        if(maxSum > 0) return max(maxSum , totalsum - minSum);
        else return maxSum;
    }
};