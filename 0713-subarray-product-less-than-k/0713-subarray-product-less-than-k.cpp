class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if( k <= 1) return 0;

        int n = a.size();
        
        int count = 0, left = 0 , right = 0;
        
        long long product = 1;
        
        
        while(right < n ){
            
            product = product*a[right];
            
            while(product >= k){
                
                product/= a[left];
                left++;
            }
            
            count += right - left +1;
            right++;
        }
        
        return count;
    }
};