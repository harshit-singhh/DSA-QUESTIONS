class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int count = 0;
        
        vector<int>prev = intervals[0];
        
        int i = 1;
        
        int n = intervals.size();
        while(i < n){
            if(intervals[i][0] >= prev[1]){
                prev = intervals[i];
            }
            
            else{
                // prev    curr
                //[1,2] [1,3] ye wala case likhne ki zaroorat nhi he because, prev abhi bhi udhar hi rhega and [1,3]
                // delete hoga
                
                
                // [1,5] [1,3] // ye 
                //  prev   curr
                
                count++;
                if(prev[1] > intervals[i][1]){
                    prev = intervals[i];
                }
            }
            i++;
        }
        
        return count;
    }
};