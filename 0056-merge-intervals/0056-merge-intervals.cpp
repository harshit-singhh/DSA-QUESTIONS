class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin() , intervals.end());
        int pairs = intervals.size();
        vector<vector<int>>ans;

        vector<int>merged = {intervals[0][0] , intervals[0][1]};
        for(int i = 1 ; i < pairs ; i++){
            if(intervals[i][0] <= merged[1]){
                merged[0] = min(merged[0] , intervals[i][0]);
                merged[1] = max(merged[1] , intervals[i][1]);
            }
            else{
                ans.push_back(merged);
                merged = intervals[i];
            }
        }

        ans.push_back(merged);
        return ans;
    }
};