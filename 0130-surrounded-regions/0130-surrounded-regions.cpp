class Solution {
public:

    bool isvalid(int newrow , int newcol , int row, int col){
        if(newrow < row && newrow >= 0 && newcol < col && newcol >= 0) {
            return true;
        }

        return false;
    }

    void capture(vector<vector<char>>&board , vector<vector<int>>&visited , int row , int col , int crow ,  int ccol){
        board[crow][ccol] = '1';
        visited[crow][ccol] = 1;
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , -1 , 0 , 1};

        for(int i = 0 ; i < 4 ; i++){
            int newrow = crow + drow[i];
            int newcol = ccol + dcol[i];

            if(isvalid(newrow , newcol , row , col ) && board[newrow][newcol] == 'O' && visited[newrow][newcol] == 0){
                capture(board , visited , row , col , newrow , newcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int row= board.size();
        int col = board[0].size();

        vector<vector<int>>visited(row , vector<int>(col , 0));

        //for top row

        for(int i = 0 ; i < col ; i++){
            if(board[0][i] == 'O'  && visited[0][i] == 0){
                capture(board , visited ,row , col , 0 , i );
            }
        }

        // for left side 

        for(int i = 0 ; i < row ; i++){
            if(board[i][0] == 'O'  && visited[i][0] == 0){
                capture(board , visited, row , col , i , 0);
            }
        }

        // for bottom 

        for(int i = 0 ; i < col ; i++){
            if(board[row-1][i] == 'O' && visited[row-1][i] == 0){
                capture(board , visited,row , col , row-1 , i);
            }
        }

        // for right side

        for(int i = 0 ; i < row ; i++){
            if(board[i][col-1] == 'O'  && visited[i][col-1] == 0){
                capture(board , visited,row , col , i , col-1);
            }
        }


        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] != '1') board[i][j] = 'X';
                else board[i][j] = 'O';
            }
        }


    }
};