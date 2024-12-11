class Solution {
public:
    int maximumBeauty(vector<int>& arr, int k) {
        
        int left = 0, right = 0, ans = 0;
        sort(arr.begin(),arr.end());

        while(right < arr.size()){
            if(arr[right] - arr[left] > 2*k) left++;
            else{
                ans = max(ans,right - left + 1);
            }
            right++;
        }

        return ans;
        
    }
};