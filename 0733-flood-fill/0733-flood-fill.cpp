class Solution {
    private:
    bool isvalid(int currrow , int currcol , int row , int col){
        if(currrow >= 0 && currrow < row && currcol >= 0 && currcol < col) return true;
        return false;
    }
    void dfs(vector<vector<int>>&image , int row , int col , int currrow , int currcol , 
    int color , int originalcolor){
        image[currrow][currcol] = color;
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , -1 , 0 , 1};

        for(int i = 0 ; i< 4 ; i++){
            int newrow = currrow + drow[i];
            int newcol = currcol + dcol[i];

            if(isvalid(newrow, newcol , row , col) && image[newrow][newcol] == originalcolor){
                dfs(image , row , col , newrow , newcol , color , originalcolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        if(color == image[sr][sc] ) return image;

        int originalcolor = image[sr][sc];
        dfs(image , n , m , sr , sc , color , originalcolor );

        return image;
    }
};