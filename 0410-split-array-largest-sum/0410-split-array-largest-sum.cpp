class Solution {
    private:
    long long NoOfPainter(vector<int>&arr, int n , long long maxTime){
        int PainterCount = 1;
        long long timeCount = arr[0];
        
        for(int i = 1 ; i < n ; i ++){
            if(timeCount + arr[i] <= maxTime){
                timeCount += arr[i];
                
            }
            else if(timeCount + arr[i] > maxTime){
                timeCount = arr[i];
                PainterCount++;
            }
        }
        
        return PainterCount;
    }
public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();

        if( k > n) return -1;
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ;i ++) maxi = max(maxi , arr[i]);
        
        long long low = maxi;
        long long high = accumulate(arr.begin(),arr.end(),0LL);
        
        long long ans = 0;
        
        while(low <= high){
            long long mid = low + ( high - low )/2;
            
            long long painters = NoOfPainter(arr,n,mid);
            
            if(painters > k){
               
                low = mid+1;
            }
            
            else if(painters <= k){
                ans = mid;
                high = mid -1;
            }
            
            
        }
        
        return ans;
    }
    
};