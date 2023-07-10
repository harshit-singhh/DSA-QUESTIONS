class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        sort(intervals.begin(),intervals.end());
        
        vector<int>mergedInterval = intervals[0];


        vector<vector<int>>ans;

        int i = 1;

        while(i < intervals.size()){
            if(intervals[i][0] > mergedInterval[1]){
                ans.push_back(mergedInterval);
                mergedInterval = intervals[i];
                
            }

            else if(intervals[i][0] <= mergedInterval[1]){
                mergedInterval[0] = min(mergedInterval[0],intervals[i][0]);
                mergedInterval[1] = max(mergedInterval[1],intervals[i][1]);
            }

            i++;
        }

        ans.push_back(mergedInterval);
        return ans;
    }
};