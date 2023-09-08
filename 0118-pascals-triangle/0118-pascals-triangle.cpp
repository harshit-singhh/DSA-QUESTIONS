class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 0 ; i < numRows ; i++){

            vector<int>stage(i+1 , 1);
            int size = stage.size();

            for (int j = 1; j < size - 1; j++) {
                stage[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(stage);
        }

        return ans;
    }
};