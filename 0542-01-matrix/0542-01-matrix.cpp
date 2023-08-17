class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>visited(n , vector<int>(m , 0));
        vector<vector<int>>dist(n , vector<int>(m , -1));

        queue<pair<int , pair<int,int>>>p; // distance , x , y

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    p.push({0 , {i , j}});
                }
            }
        }

        int drow[] = {-1, 0 , 1 , 0};
        int dcol[] = {0 , -1 , 0 , 1};

        while(!p.empty()){
            int distance = p.front().first;
            int row = p.front().second.first;
            int col = p.front().second.second;

            p.pop();

            dist[row][col] = distance;

            for(int i = 0 ; i < 4 ; i ++){
                int newrow = row + drow[i];
                int newcol = col + dcol[i];

                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
                && visited[newrow][newcol] == 0 ){

                    visited[newrow][newcol] = 1;
                    p.push({distance+1 , {newrow , newcol}});
                }
            }

        }

        return dist;
    }
};