class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int left = 0;
        int n = matrix.size();
        int m= matrix[0].size();
        int right = m-1;
        int bottom = n-1;
        
        int total = n*m;
        vector<int>answer;
        
        // if(k>total){
        //     return -1;
        // }
        int count = 0;
        
        while(count != total){
            for(int i = left ;count != total && i <= right ; i++){
                answer.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for(int i = top; count != total && i <= bottom; i ++){
                answer.push_back(matrix[i][right]);
                count++;
            }
            right --;
            for(int i = right ;count != total && i >= left ; i--){
                answer.push_back(matrix[bottom][i]);
                count++;
            }
            bottom --;
            for(int i = bottom ;count != total && i >= top ; i--){
                answer.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }   
        
        return answer;
    
    }
};