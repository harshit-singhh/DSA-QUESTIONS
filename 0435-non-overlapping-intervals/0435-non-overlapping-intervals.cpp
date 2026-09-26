class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int removal = 0;

        int n = intervals.size();
        sort(intervals.begin() , intervals.end());

        int index = 1;
        vector<int>lastInterval = intervals[0];
        while(index < n){
            if(intervals[index][0] >= lastInterval[0] && intervals[index][1] <= lastInterval[1]){
                lastInterval = intervals[index];
                removal++;
                index++;
            }
            else if(intervals[index][0] < lastInterval[1]){
                removal++;
                index++;
            }
            else{
                lastInterval = intervals[index];
                index++;
            }
        }

        return removal;
    }
};