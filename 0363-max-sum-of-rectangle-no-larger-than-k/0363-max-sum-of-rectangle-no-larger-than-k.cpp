class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        for(int colstart = 0 ; colstart < m ; colstart++){
            vector<int>sum(n);

            for(int colend = colstart ; colend < m ; colend++){
                
                set<int>st = {0};
                for(int i = 0 ; i < n ; i ++){
                    sum[i]+=matrix[i][colend];
                }
                int preJ = 0 , currMax = INT_MIN;
                for(auto run_sum : sum){
                    preJ += run_sum;

                    auto it = st.lower_bound(preJ-k);

                    if(it != st.end()){
                        currMax = max(currMax , preJ - *it);
                    }
                    
                    st.insert(preJ);
                }

                ans = max(ans , currMax);

            }
        }

        return ans;
    }



        // int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // if (matrix.empty()) return 0;
        // int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        // for (int l = 0; l < col; ++l) {
        //     vector<int> sums(row, 0);
        //     for (int r = l; r < col; ++r) {
        //         for (int i = 0; i < row; ++i) {
        //             sums[i] += matrix[i][r];
        //         }
                
        //         // Find the max subarray no more than K 
        //         set<int> accuSet;
        //         accuSet.insert(0);
        //         int curSum = 0, curMax = INT_MIN;
        //         for (int sum : sums) {
        //             curSum += sum;
        //             set<int>::iterator it = accuSet.lower_bound(curSum - k);
        //             if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
        //             accuSet.insert(curSum);
        //         }
        //         res = std::max(res, curMax);
        //     }
        // }
        // return res;
    
};