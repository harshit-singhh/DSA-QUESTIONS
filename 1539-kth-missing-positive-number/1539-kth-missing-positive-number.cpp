class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid = left+(right - left)/2;

            int missing_nums = arr[mid] - mid - 1;
            if(missing_nums < k){
                left = mid+1;
            }
            else if(missing_nums >= k){
                right = mid-1;
            }
        }

        if(right < 0 ) return k;
        int current_missing = arr[right] - right - 1;
        int num_to_find = k - current_missing;
        return arr[right] + num_to_find;
    }
};