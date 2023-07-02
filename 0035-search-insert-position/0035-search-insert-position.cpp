class Solution {
public:
    int searchInsert(vector<int>& Arr, int k) {
        int start = 0;
        int N = Arr.size();
        int end = N-1;
        
        int mid = start + (end - start )/2;
        
        while(start <= end){
            if(Arr[mid] == k){
                return mid;
            }
            else if(Arr[mid]>k){
                end  = mid -1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return start;
    }
};