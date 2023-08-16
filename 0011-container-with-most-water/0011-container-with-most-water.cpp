class Solution {
public:
    int maxArea(vector<int>& arr) {
    int left = 0;
    int len = arr.size();
    int right = len-1;
    long long maxarea = 0;
    
    while(left < right){
        int base = right - left;
        int height = min(arr[left] , arr[right]);
        
        long long area = height*base;
        
        maxarea = max(maxarea , area);
        
        if(arr[left] < arr[right]){
            left++;
        }
        else{
            right--;
        }
    }
    
    
    return maxarea;
    }
};