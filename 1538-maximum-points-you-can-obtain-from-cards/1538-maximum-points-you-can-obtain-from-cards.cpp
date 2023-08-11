class Solution {
public:
    int maxScore(vector<int>& arr, int k) {

        int n = arr.size();

        if(k == n) return accumulate(arr.begin(), arr.end(),0);
        if(k>n) return -1;
        
        vector<long long>SumAteachIndex(n);
        
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){ //prefix sum
            sum += arr[i];
            SumAteachIndex[i] = sum;
        }

        long long totalsumOfArray = SumAteachIndex[n-1];
        
        int skipWindow = n - k; // jesi arr me 10 element he and humko 4 select karke max sum nikalna he then 
        // 6 window hmesha bach jaengi. jiska sum hmare matlab ka nhi he.
        
        long long maxSum = 0;
        
        int left = 0, right = skipWindow - 1;
        
        while(right < n){
            
            long long ImpSum = 0;
            
            if(left == 0 ){
                ImpSum = totalsumOfArray - (SumAteachIndex[right]);
            }
            else{
                ImpSum = totalsumOfArray - SumAteachIndex[right] + SumAteachIndex[left-1]; // dry run kroge to smj jaoge
            }
            
            left++;
            right++;
            
            maxSum = max(maxSum, ImpSum);
        }
        
        return maxSum;
        
    }
};