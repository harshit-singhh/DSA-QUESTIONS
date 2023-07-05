class Solution {
public:

    int atmost( vector<int>& arr, int k){
        
        // this is the general format for atmost wale questions.

        int n = arr.size();
        int left = 0, right = 0, totalSubarrays = 0 , sum = 0;
        
        while(right < n){
            
            sum+=arr[right];
            
            while(sum > k){
                sum -= arr[left];
                left++;
            }
            
            totalSubarrays += right-left+1;
            right++;
        }
        
        return totalSubarrays;
        
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
        
        int n = arr.size();
        for(int i = 0 ; i < n ; i ++){
            if(arr[i] % 2 == 0) arr[i] = 0;
            else arr[i] = 1;
        }
        
        return atmost(arr,k) - atmost(arr,k-1);
        
        
    }
};