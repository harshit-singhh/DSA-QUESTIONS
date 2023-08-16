#define ll long long
class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        int n = arr.size();
        ll firstmax = INT_MIN;
        ll secondmax = INT_MIN;
        ll thirdmax = INT_MIN;
        
        ll smallestNeg = INT_MAX;
        ll secondSmallestNeg = INT_MAX;
        
        for(int i = 0 ; i <  n; i++){
            if(arr[i] >= firstmax){
                thirdmax = secondmax;
                secondmax = firstmax;
                firstmax = arr[i];
            }
            else if(arr[i] <= firstmax && arr[i] >= secondmax){
                thirdmax = secondmax;
                secondmax = arr[i];
            }
            else if(arr[i] <= secondmax && arr[i] >= thirdmax){
                thirdmax = arr[i];
            }
            
            
            if(arr[i] <= smallestNeg){
                secondSmallestNeg = smallestNeg;
                smallestNeg = arr[i];
            }
            else if(arr[i] <= secondSmallestNeg && arr[i] >= smallestNeg){
                secondSmallestNeg = arr[i];
            }
        }
        
        ll ans1 = firstmax*secondmax*thirdmax;
        ll ans2 = smallestNeg*secondSmallestNeg*firstmax;
        
        return max(ans1 , ans2);
        
        
        
    
    }
};