class Solution {
public:
    int candy(vector<int>& arr) {
        int candy = 0;
        int N = arr.size();
        if(N==1) return 1;
        
        vector<int>freq(N,1); // because sabke pas minimum 1 candy to hogi hi.
        
        for(int i = 1 ; i < N ; i++){
            if(arr[i] > arr[i-1] && freq[i] <= freq[i-1]) freq[i] = freq[i-1] + 1; 
        }
        
        for(int i = N-2 ; i >= 0 ; i--){
            if(arr[i] > arr[i+1] && freq[i] <= freq[i+1]) freq[i] = freq[i+1] + 1;
        }
        
        // if(arr[0] > arr[1]) freq[0] = freq[1] +1;
        // if(arr[N-1] > arr[N-2]) freq[N-1] = freq[N-2]+1; 
        
        int sum = accumulate(freq.begin(), freq.end(), 0);
        
        return sum;
    }
};