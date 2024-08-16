class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxiTillNow = arrays[0].back();
        int miniTillNow = arrays[0][0];

        int n = arrays.size();

        int result = 0;
        for(int i = 1 ; i < n ; i++){

            int diff1 = abs(maxiTillNow - arrays[i][0]);
            int diff2 = abs(miniTillNow - arrays[i].back());
            result = max(diff1 , max(diff2 ,result));
            maxiTillNow = max(maxiTillNow , arrays[i].back());
            miniTillNow = min(miniTillNow , arrays[i][0]);

        }

        return result;

        
        
    }
};