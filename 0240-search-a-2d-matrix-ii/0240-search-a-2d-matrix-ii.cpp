class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r= matrix.size();
        int c = matrix[0].size();

        int row = 0;
        int col = c-1;

        while(col >= 0 && row < r){
            if(matrix[row][col] == target){
                return true;
            }

            else if(matrix[row][col] > target){
                col--;
            }
            else if(matrix[row][col] < target){
                row++;
            }
        }

        return false;
    }
};