class Solution {
    bool isvalid(int newrow , int newcol , int r , int c){

        if(newrow >= 0 && newrow < r && newcol >= 0 && newcol <c) return true;
        return false;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>>matrix(row , vector<int>(col , 0));

        int dx[] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int dy[] = {0 , -1 , -1 , -1 , 0 , 1 , 1 , 1};

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int count = 0;

                for(int k = 0 ; k < 8 ; k++){
                    int newrow = i + dx[k];
                    int newcol = j + dy[k];

                    if(isvalid(newrow , newcol , row , col) && board[newrow][newcol] == 1) count++;


                }

                if(count == 1) matrix[i][j] = 0;
                else if(board[i][j] == 1 && (count == 2 || count == 3)){
                    matrix[i][j] = 1;
                }

                else if(board[i][j] == 1 && count > 3){
                    matrix[i][j] = 0;
                }

                else if(board[i][j] == 0 && count == 3){
                    matrix[i][j] = 1;
                }
            }
        }

        board = matrix;

    }
};