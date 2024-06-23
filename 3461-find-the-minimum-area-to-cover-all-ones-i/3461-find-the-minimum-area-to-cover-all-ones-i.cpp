class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int maxtop = INT_MIN;
        int maxleft = INT_MIN;
        int minright = INT_MAX;
        int minbottom = INT_MAX;
        int row= grid.size();
        int col = grid[0].size();

        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1){
                    int top = row - i;
                    int left = col - j;
                    int right = col - j;
                    int bottom = row - i;
                    maxtop = max(maxtop , top);
                    maxleft = max(maxleft , left);
                    minright = min(minright , right);
                    minbottom = min(minbottom , bottom);
                }
            }
        }

        int base = abs(maxleft - minright) + 1;
        int height = (maxtop - minbottom) + 1;

        return base*height;
    }
};