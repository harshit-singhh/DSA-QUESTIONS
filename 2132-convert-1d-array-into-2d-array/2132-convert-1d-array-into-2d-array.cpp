class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {


        int size = original.size();

        if(m*n < size || m*n > size) return {};
        vector<vector<int>>ans;
        int index = 0;
        for(int i = 0 ; i < m ; i++){
            
            vector<int>temp;

            int level = i*n;
            for(int i = 0 ; i < n ; i++){
                temp.push_back(original[level+i]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};