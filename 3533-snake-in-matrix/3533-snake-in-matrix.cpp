class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& arr) {
        
        int row = 0 , col = 0;

        int size = arr.size();
        for(int i = 0 ; i < size ; i++){
            if(arr[i] == "RIGHT") col++;
            else if(arr[i] == "DOWN") row++;
            else if(arr[i] == "LEFT") col--;
            else if(arr[i] == "UP") row--;
        }


        return (row*n + col);
    }
};