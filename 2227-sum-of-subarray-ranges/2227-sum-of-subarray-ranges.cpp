class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        
        long long sum = 0;
        int n = arr.size();
        for(int i = 0 ; i < n ; i ++){
            
            int maxi = arr[i];
            int mini = arr[i];
            
            for(int j = i ; j < n ; j ++){
                
                if(arr[j] > maxi) maxi = arr[j];
                if(arr[j] < mini) mini = arr[j];
                
                sum+=(maxi-mini);
            }
        }
        
        return sum;
    }
};