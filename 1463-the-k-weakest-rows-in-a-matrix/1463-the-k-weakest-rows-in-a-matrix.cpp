class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>q;

        int row = mat.size();
        int col = mat[0].size();

        for(int i = 0 ; i < row ; i++){
            int count = 0;
            for(int j = 0 ; j < col ; j++){
                if(mat[i][j] == 1) count ++;
            }

            q.push({count , i});
        }

        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};