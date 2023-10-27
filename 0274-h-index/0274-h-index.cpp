class Solution {
    private:
    bool possible(vector<int>&arr, int n , int x){
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            if(arr[i] >= x){
                count++;
            }
        }

        return count >= x;
    }
public:
    int hIndex(vector<int>& arr) {
        
        int n = arr.size();
        int low  = 0;

        int high = *max_element(arr.begin() , arr.end());

        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(possible(arr, n ,  mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high  = mid -1;
            }
        }

        return ans;
    }
};